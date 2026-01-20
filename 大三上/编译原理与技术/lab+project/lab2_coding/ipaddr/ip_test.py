#!/usr/bin/env python3
# encoding: utf-8

import ctypes
import os
import pickle


"""
Test cases originated from:

LeetCode 468. Validate IP Address
https://leetcode.com/problems/validate-ip-address/
"""


# 获取当前工作目录（用于定位同目录下的共享库 libip.so）
cwd = os.getcwd()
# 将工作目录与库文件名拼接成完整路径
lib_path = os.path.join(cwd, 'libip.so')
# 使用 ctypes 加载共享库，以便在 Python 中调用其中的 C 函数
lib = ctypes.cdll.LoadLibrary(lib_path)


def valid_ip_address(ip):
    # 从加载的库中获取名为 validIPAddress 的导出函数
    func = lib.validIPAddress
    # 告诉 ctypes 该 C 函数返回一个 C 字符串 (char *)，以便 Python 接收为 bytes
    func.restype = ctypes.c_char_p
    # 将 Python 字符串编码为 ASCII 字节串，准备传入 C 函数
    ip_b = ip.encode('ascii')
    # 将字节串包装为 ctypes 的 c_char_p（C 风格字符串指针）
    ip_buf = ctypes.c_char_p(ip_b)
    # 调用 C 函数并将返回的 bytes 解码为 Python 字符串返回
    return func(ip_buf).decode()


# 从 data.pickle 中加载测试用例（假定为字典：{input: expected_output}）
test_cases = pickle.load(open('data.pickle', 'rb'))

# 遍历所有测试用例并用 C 实现的函数验证输出
for input_, output in test_cases.items():
    # 将输入字符串加上换行后传入（C 实现可能期望以换行结尾的行输入）
    ans = valid_ip_address(input_+'\n')
    # 比对 C 函数的返回值与期望值，若不一致则打印信息并终止测试
    if ans != output:
        print('Wrong!')
        print('Input: %s' % input_)
        print('Excepted: %s' % output)
        print('Your answer: %s' % ans)
        break
else:
    # 如果没有通过 break（即所有测试都通过），执行此处
    print('All tests passed!')
