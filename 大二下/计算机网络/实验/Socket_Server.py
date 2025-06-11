"""
Server
Edited by Zihan Dou
"""

import socket
import os
import argparse
import threading
import ssl
import logging
from datetime import datetime


class TCPFileServer:
    def __init__(self, host='0.0.0.0', port=9000, use_ssl=False, certfile=None, keyfile=None):
        """
        初始化TCP文件服务器，设置监听地址、端口和SSL配置。

        Args:
            host (str): 服务器监听的IP地址。默认为'0.0.0.0'（所有可用接口）。
            port (int): 服务器监听的端口号。默认为9000。
            use_ssl (bool): 如果为True，服务器将使用SSL/TLS加密。默认为False。
            certfile (str): SSL证书文件路径（如果启用SSL则必需）。
            keyfile (str): SSL密钥文件路径（如果启用SSL则必需）。
        """

        # 初始化服务器参数，包括监听地址、端口、是否启用SSL、证书文件和密钥文件路径
        self.host = host
        self.port = port
        self.use_ssl = use_ssl
        self.certfile = certfile
        self.keyfile = keyfile
        self.sock = None  # 将sock初始化为None，以便在启动前检查其状态
        self.running = False  # 控制服务器运行状态的标志

        # 设置日志记录器
        logging.basicConfig(
            filename='server_access.log',  # 日志文件名
            level=logging.INFO,  # 记录级别
            format='%(asctime)s [%(levelname)s] %(message)s',  # 日志格式
            datefmt='%Y-%m-%d %H:%M:%S'  # 时间格式
        )

    def start(self):
        """
        绑定服务器地址和端口，并开始监听传入连接。
        如果启用SSL，则处理SSL上下文的创建。
        在循环中接受客户端连接，并为每个客户端创建一个新线程进行处理。
        """
        # 绑定服务器地址和端口，并开始监听传入连接
        try:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            # 允许重用地址，避免服务器重启后出现“地址已被占用”的错误
            self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            self.sock.bind((self.host, self.port))
            self.sock.listen(5)  # 设置最大等待连接数为 5
            self.running = True
            print(f"[INFO] Server listening on {self.host}:{self.port} {'with SSL' if self.use_ssl else ''}")
            logging.info(f"Server started on {self.host}:{self.port} {'with SSL' if self.use_ssl else ''}")

            context = None
            if self.use_ssl:
                # 如果启用了 SSL，需要提供证书和密钥文件
                if not self.certfile or not self.keyfile:
                    print("[ERROR] SSL enabled but cert or key file not provided. Aborting server start.")
                    logging.error("SSL enabled but cert or key file not provided. Server not started.")
                    self.stop()  # 确保在SSL设置失败时关闭套接字
                    return
                try:
                    # 创建 SSL 上下文并加载证书和密钥
                    context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
                    context.load_cert_chain(certfile=self.certfile, keyfile=self.keyfile)
                except ssl.SSLError as e:
                    print(f"[ERROR] Failed to load SSL certificate or key: {e}. Aborting server start.")
                    logging.error(f"Failed to load SSL certificate or key: {e}. Server not started.")
                    self.stop()
                    return
                except FileNotFoundError as e:
                    print(f"[ERROR] SSL certificate or key file not found: {e}. Aborting server start.")
                    logging.error(f"SSL certificate or key file not found: {e}. Server not started.")
                    self.stop()
                    return

            while self.running:
                try:
                    # 接受客户端连接请求
                    client, addr = self.sock.accept()
                    if self.use_ssl:
                        try:
                            # 如果启用 SSL，将连接包装为加密连接
                            client = context.wrap_socket(client, server_side=True)
                        except ssl.SSLError as e:
                            print(f"[ERROR] SSL handshake failed with {addr}: {e}")
                            logging.error(f"SSL handshake failed with {addr}: {e}")
                            client.close()
                            continue
                    # 为每个客户端连接创建新的线程进行处理，防止阻塞主线程
                    t = threading.Thread(target=self.handle_client, args=(client, addr), daemon=True)
                    t.start()
                except socket.timeout:
                    # 如果在监听套接字上设置了超时，可能会发生这种情况
                    continue
                except OSError as e:
                    # 捕获套接字接受连接时的操作系统错误，例如文件描述符耗尽
                    if self.running:  # 只有当服务器仍然应该运行时才记录为错误
                        print(f"[ERROR] Socket accept error: {e}")
                        logging.error(f"Socket accept error: {e}")
                    break  # 如果套接字不再可用，则跳出循环
                except Exception as e:
                    # 捕获主服务器循环中的任何其他意外错误
                    print(f"[CRITICAL] An unexpected error occurred in the main server loop: {e}")
                    logging.critical(f"An unexpected error occurred in the main server loop: {e}")
                    break  # 遇到严重错误时考虑停止服务器

        except socket.error as e:
            # 捕获套接字相关的启动错误，如端口已被占用
            print(f"[CRITICAL] Failed to start server on {self.host}:{self.port}: {e}")
            logging.critical(f"Failed to start server on {self.host}:{self.port}: {e}")
        except Exception as e:
            # 捕获服务器启动期间的任何未处理错误
            print(f"[CRITICAL] An unhandled error occurred during server startup: {e}")
            logging.critical(f"An unhandled error occurred during server startup: {e}")
        finally:
            self.stop()  # 确保在循环中断或发生异常时进行正确的资源清理

    def stop(self):
        """
        停止服务器并关闭套接字。
        将运行标志设置为False，并尝试优雅地关闭套接字。
        """
        # 停止服务器并关闭套接字
        self.running = False
        if self.sock:
            print("[INFO] Shutting down server...")
            logging.info("Server shutting down.")
            try:
                # 尝试优雅地关闭套接字的读写两半
                self.sock.shutdown(socket.SHUT_RDWR)
            except OSError as e:
                logging.warning(f"Error during socket shutdown: {e}")
            self.sock.close()
            self.sock = None  # 清除对套接字的引用

    def handle_client(self, conn, addr):
        """
        处理单个客户端连接。
        从客户端接收请求的文件名，执行验证，并尝试将文件发送回去。包括各种情况的错误处理。

        Args:
            conn (socket.socket or ssl.SSLSocket): 客户端套接字对象。
            addr (tuple): 连接客户端的地址（IP，端口）。
        """
        # 处理单个客户端连接
        client_ip, client_port = addr
        print(f"[INFO] Connection from {client_ip}:{client_port}")
        logging.info(f"Connection from {client_ip}:{client_port}")
        try:
            # 设置接收数据的超时时间，以防止客户端长时间不发送数据导致挂起
            conn.settimeout(10)  # 10 秒超时用于初始文件名接收

            data = b''
            # 定义最大文件名长度以防止资源耗尽或恶意输入
            max_filename_length = 255
            while not data:
                chunk = conn.recv(1024)  # 每次最多接收 1024 字节
                if not chunk:
                    # 客户端在发送完整文件名之前断开连接
                    print(f"[WARNING] Client {client_ip}:{client_port} disconnected before sending filename.")
                    logging.warning(f"Client {client_ip}:{client_port} disconnected before sending filename.")
                    return
                data += chunk
                # 检查接收到的数据长度是否超过文件名最大限制
                if len(data) > max_filename_length + 10:  # +10 用于换行符前的潜在额外字节，防止截断
                    print(
                        f"[ERROR] Filename too long from {client_ip}:{client_port}. Max: {max_filename_length} bytes.")
                    logging.error(
                        f"Filename too long from {client_ip}:{client_port}. Max: {max_filename_length} bytes.")
                    conn.sendall(b"ERROR: Filename too long.\n")
                    return

            filename_raw = data.split(b'\n', 1)[0]
            try:
                # 解码并提取文件名，去除多余空白字符
                filename = filename_raw.decode('utf-8').strip()
            except UnicodeDecodeError:
                # 处理文件名编码错误
                print(f"[ERROR] Received non-UTF-8 filename from {client_ip}:{client_port}.")
                logging.error(f"Received non-UTF-8 filename from {client_ip}:{client_port}.")
                conn.sendall(b"ERROR: Invalid filename encoding.\n")
                return

            # 基本路径遍历预防：检查文件名中是否包含敏感路径字符
            if ".." in filename or "/" in filename or "\\" in filename:
                print(
                    f"[WARNING] Path traversal attempt detected from {client_ip}:{client_port} with filename: {filename}")
                logging.warning(
                    f"Path traversal attempt detected from {client_ip}:{client_port} with filename: {filename}")
                conn.sendall(b"ERROR: Invalid filename.\n")
                return

            print(f"[INFO] Requested file: {filename} from {client_ip}:{client_port}")
            logging.info(f"Client {client_ip}:{client_port} requested file: {filename}")

            file_path = os.path.join("D:/Projects/Python/Socket/files_in_server", filename)
            # 确保文件位于指定目录内
            if not os.path.isfile(file_path) or not os.path.commonprefix(
                    (os.path.abspath(file_path), os.path.abspath("D:/Projects/Python/Socket/files_in_server"))) == os.path.abspath(
                    "D:/Projects/Python/Socket/files_in_server"):
                err = f"ERROR: File '{filename}' not found or invalid path."
                print(f"[ERROR] {err} for {client_ip}:{client_port}")
                logging.warning(f"File not found or invalid path: {filename} requested by {client_ip}:{client_port}")
                conn.sendall(err.encode() + b'\n')
            else:
                try:
                    # 发送响应表示开始传输
                    status = "SUCCESS:"
                    filesize = os.path.getsize(file_path)
                    response = status + str(filesize)
                    conn.sendall(response.encode() + b'\n')
                    print(f"[SUCCESS] Start the file transfer. The total file size is: {filesize} bytes.")
                    logging.info(f"Start the file transfer. The total file size is: {filesize} bytes.")

                    total_sent = 0
                    with open(file_path, 'rb') as f:
                        conn.settimeout(None)  # 文件传输期间禁用超时，防止大文件传输中断
                        while True:
                            chunk = f.read(4096)  # 每次读取最多 4096 字节
                            if not chunk:
                                break  # 文件读取完毕
                            sent = conn.send(chunk)
                            if sent == 0:  # 如果发送了零字节，表示客户端可能已断开
                                print(
                                    f"[WARNING] Zero bytes sent to {client_ip}:{client_port} during file transfer of '{filename}'.")
                                logging.warning(
                                    f"Zero bytes sent to {client_ip}:{client_port} during file transfer of '{filename}'.")
                                break
                            total_sent += sent
                    print(f"[INFO] Sent {total_sent} bytes of '{filename}' to {client_ip}:{client_port}")
                    logging.info(f"Sent {total_sent} bytes of '{filename}' to {client_ip}:{client_port}")
                except FileNotFoundError:
                    err = f"ERROR: File '{filename}' not found on server."
                    print(f"[ERROR] {err}")
                    logging.error(f"File not found during open attempt: {filename} for {client_ip}:{client_port}")
                    conn.sendall(err.encode() + b'\n')
                except IOError as e:
                    # 处理文件读取时的输入/输出错误
                    err = f"ERROR: Error reading file '{filename}': {e}"
                    print(f"[ERROR] {err}")
                    logging.error(f"Error reading file '{filename}' for {client_ip}:{client_port}: {e}")
                    conn.sendall(err.encode() + b'\n')
                except BrokenPipeError:
                    # 当客户端在传输过程中断开连接时发生此错误
                    print(
                        f"[WARNING] Client {client_ip}:{client_port} disconnected unexpectedly during file transfer of '{filename}'.")
                    logging.warning(
                        f"Client {client_ip}:{client_port} disconnected unexpectedly during file transfer of '{filename}'.")
                except Exception as e:
                    # 捕获发送文件时的任何其他意外错误
                    err = f"ERROR: An unexpected error occurred while sending file: {e}"
                    print(f"[ERROR] {err}")
                    logging.error(f"Unexpected error sending file '{filename}' to {client_ip}:{client_port}: {e}")
                    conn.sendall(err.encode() + b'\n')

        except socket.timeout:
            # 客户端在发送文件名期间超时
            print(f"[WARNING] Client {client_ip}:{client_port} timed out during filename reception.")
            logging.warning(f"Client {client_ip}:{client_port} timed out during filename reception.")
            try:
                conn.sendall(b"ERROR: Timeout during filename reception.\n")
            except Exception as e:
                logging.error(f"Error sending timeout error to {client_ip}:{client_port}: {e}")
        except ConnectionResetError:
            # 客户端强制关闭连接
            print(f"[WARNING] Client {client_ip}:{client_port} reset the connection.")
            logging.warning(f"Client {client_ip}:{client_port} reset the connection.")
        except ConnectionAbortedError:
            # 客户端中止连接
            print(f"[WARNING] Client {client_ip}:{client_port} aborted the connection.")
            logging.warning(f"Client {client_ip}:{client_port} aborted the connection.")
        except ssl.SSLError as e:
            # 处理SSL相关的错误
            print(f"[ERROR] SSL error during client handling for {client_ip}:{client_port}: {e}")
            logging.error(f"SSL error during client handling for {client_ip}:{client_port}: {e}")
        except Exception as e:
            # 捕获 handle_client 中的任何未处理异常
            print(f"[ERROR] Unhandled exception in handle_client for {client_ip}:{client_port}: {e}")
            logging.error(f"Unhandled exception in handle_client for {client_ip}:{client_port}: {e}",
                          exc_info=True)  # exc_info=True 会记录完整的堆栈信息
        finally:
            if conn:
                try:
                    if isinstance(conn, ssl.SSLSocket):
                        conn.unwrap()  # 尝试干净地解包SSL套接字
                    conn.shutdown(socket.SHUT_RDWR)
                except OSError as e:
                    logging.warning(f"Error during client socket shutdown for {client_ip}:{client_port}: {e}")
                finally:
                    conn.close()
                    print(f"[INFO] Connection to {client_ip}:{client_port} closed.")
                    logging.info(f"Connection to {client_ip}:{client_port} closed.")


def main():
    """
    解析命令行参数，如果文件目录不存在则创建，初始化TCP文件服务器并启动。
    处理KeyboardInterrupt以实现优雅关机。
    """
    # 解析命令行参数
    parser = argparse.ArgumentParser(description="TCP File Transfer Server")
    parser.add_argument('--host', default='0.0.0.0', help='Host/IP to bind')  # 监听的主机地址
    parser.add_argument('--port', type=int, default=9000, help='Port to bind')  # 监听的端口号
    parser.add_argument('--ssl', action='store_true', help='Enable SSL')  # 是否启用 SSL
    parser.add_argument('--cert', help='SSL certificate file (PEM)')  # SSL 证书文件路径
    parser.add_argument('--key', help='SSL key file (PEM)')  # SSL 密钥文件路径
    args = parser.parse_args()

    # 创建用于存放文件的目录（如果不存在）
    if not os.path.exists("D:/Projects/Python/Socket/files_in_server"):
        os.makedirs("D:/Projects/Python/Socket/files_in_server")
        print("[INFO] Created directory: D:/Projects/Python/Socket/files_in_server")
        logging.info("Created directory: D:/Projects/Python/Socket/files_in_server")

    # 创建服务器实例，并传入参数启动服务
    server = TCPFileServer(
        host=args.host,
        port=args.port,
        use_ssl=args.ssl,
        certfile=args.cert,
        keyfile=args.key
    )
    try:
        server.start()
    except KeyboardInterrupt:
        print("\n[INFO] Server interrupted by user (Ctrl+C).")
        logging.info("Server interrupted by user (Ctrl+C).")
    finally:
        server.stop()


if __name__ == '__main__':
main()
