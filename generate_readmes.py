import os

# 1. Change this to the path of your DSA_CPP folder
folder_path = r"E:\DSA cpp - Copy"

# 2. Go through all files in the folder
for root, dirs, files in os.walk(folder_path):
    for file in files:
        if file.endswith(".cpp"):
            # Path of this cpp file
            cpp_path = os.path.join(root, file)
            
            # Path of README for this file
            readme_path = os.path.join(root, f"{file.replace('.cpp', '')}_README.md")

            # Skip if README already exists
            if os.path.exists(readme_path):
                continue

            # Content of README
            content = f"""# {file.replace('.cpp', '').capitalize()}

## 📘 Description
This program implements **{file.replace('.cpp', '')}** in C++.

## ⚙️ How to Compile and Run
g++ {file} -o {file.replace('.cpp', '')}
./{file.replace('.cpp', '')}

## 🧩 File Info
- **File name:** {file}
- **Location:** {root}
"""

            # 3. Write the README.md file
            with open(readme_path, "w", encoding="utf-8") as f:

                f.write(content)

print("✅ README.md files created for all .cpp files!")
