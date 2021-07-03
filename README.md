# 关于本仓库

这是关于《计算广告（第二版）》一书的笔记，里面包含：

1. 书中一些算法的可执行代码
2. 一些基础的 C++ 概念的笔记（多为示例代码）
3. 一些数据科学的概念和证明

# 如何使用

可以使用 VS Code 的 Code Runner 插件来快速运行本仓库中的 C++ 代码。本仓库使用 C++11.

## 让 Code Runner 使用 C++11

1. 打开 VS Code 设置文件：在 Extensions 界面点击 Code Runner 的小齿轮，选择 Extension Setting，找到 Code-runner: Executor Map 这一项，点击 Edit in settings.json
2. 将 `code-runner.executorMap` 这里项加入 `-std=c++11` 这个代码：

```json
"code-runner.executorMap": {
		"cpp": "cd $dir && g++ -std=c++11 $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
    },
```

## 让 VS Code 不对 C++11 的特性的语句报红

1. 打开 VS Code 设置文件：在 Extensions 界面点击 C/C++ 的小齿轮，选择 Extension Setting，找到 C_Cpp › Default: Compiler Args 这一项，点击 Edit in settings.json
2. 将 `C_Cpp.default.compilerArgs` 这一项改为：

```json
    "C_Cpp.default.compilerArgs": [
        "-g",
		"${file}",
        "-std=c++11",
		"-o",
		"${fileDirname}/${fileBasenameNoExtension}"
    ],
```
