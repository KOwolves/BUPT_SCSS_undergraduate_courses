import subprocess
import os

# 确保 bin 目录存在
if not os.path.exists("bin"):
    print("Error: bin directory not found. Please run 'make' first.")
    exit(1)

# Test test_2_o01.bpl (正确测试用例)
for i in range(1, 2):
    name = f"o0{i}" 
    # Define the input file path
    input_file = f"test/test_2_{name}.bpl"
    # Define the output file path
    output_file = f"test/test_2_{name}.out"
    
    # 检查输入文件是否存在
    if not os.path.exists(input_file):
        print(f"Warning: {input_file} not found, skipping.")
        continue

    # Define the command to run the compiler
    command = ["./bin/bplc", input_file]
    
    # Open the output file for writing
    try:
        with open(output_file, 'w') as f:
            # Run the command and redirect the output to the output file
            subprocess.run(command, stdout=f, check=True)
            print(f"{input_file} > {output_file} OK.")
    except Exception as e:
        print(f"Error running {input_file}: {e}")

# Test test_2_r01.bpl to test_2_r15.bpl (错误测试用例)
for i in range(1, 16):
    if i <= 9:
        name = f"0{i}"
    else:
        name = f"{i}"
    
    # Define the input file path.
    input_file = f"test/test_2_r{name}.bpl"
    # Define the output file path
    output_file = f"test/test_2_r{name}.out"
    
    # 检查输入文件是否存在
    if not os.path.exists(input_file):
        print(f"Warning: {input_file} not found, skipping.")
        continue

    # Define the command to run the compiler
    command = ["./bin/bplc", input_file]
    
    # Open the output file for writing
    try:
        with open(output_file, 'w') as f:
            # Run the command and redirect the output to the output file
            subprocess.run(command, stdout=f)
            print(f"{input_file} > {output_file} OK.")
    except Exception as e:
        print(f"Error running {input_file}: {e}")