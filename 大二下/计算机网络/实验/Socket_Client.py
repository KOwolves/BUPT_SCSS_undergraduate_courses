import datetime
import socket
import os

class TCPFileClient:
    def __init__(self, server_ip, filename):
        """
        初始化TCP文件客户端。

        Args:
            server_ip (str): 文件服务器的IP地址。
            filename (str): 要从服务器请求下载的文件名。
        """
        self.server_ip = server_ip
        self.filename = filename

    def receive_file(self,):
        """
        连接到服务器，发送文件名请求，并接收文件。
        接收到的文件将保存到客户端指定目录下的一个新文件中，文件名包含日期和时间戳。
        """
        PORT = 9000
        new_filename = f"recv_{datetime.date.today().strftime('%Y%m%d')}_{datetime.datetime.now().strftime('%H%M%S')}_{os.path.basename(self.filename)}"

        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
            sock.connect((self.server_ip, PORT))
            sock.sendall(self.filename.encode())

            response = sock.recv(1024).decode()
            status, filesize_str = response.split(":")
            if status == "ERROR":
                print(response)
                return

            filesize = int(filesize_str)
            print(f"Receiving file ({filesize} bytes)...")

            received_bytes = 0
            with open(f"D:/Projects/Python/Socket/files_in_client/{new_filename}", 'wb') as f:
                while received_bytes < filesize:
                    data = sock.recv(4096)
                    if not data:
                        break
                    f.write(data)
                    received_bytes += len(data)

            print(f"File received: {new_filename}")
            print(f"Total bytes received: {received_bytes}\n")

if __name__ == '__main__':
    ip = "127.0.0.1"

    while True:
        file = input("Enter file name to download (or 'quit' to exit): ").strip()
        if file.lower() == 'quit':
            print("Exiting client.")
            break
        if file == '':
            continue  # 空输入跳过
        client = TCPFileClient(ip, file)

        client.receive_file()
