# Modern C++ Course ⚙️🚀

![Language](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge\&logo=cplusplus\&logoColor=white)

> **This repository is *not* an introductory programming course.**
> It is designed for people who already code (especially in C) and want to learn C++ with a focus on performance, design, and best practices.

---

## 📖 About This Repository

This is the workspace for a **C++ course (in development)**, organized around code, examples, and interactive notebooks.
There is no video content — all learning happens here through hands-on experimentation and guided practice.

🎯 **Goal:**
Teach modern C++ in a clear, practical, and applied way, covering:

* Modern paradigms (RAII, OOP, generic, functional)
* Effective use of the STL and advanced language features
* Best practices and safe code
* Professional project organization
* Modern build and compilation tools

No basics like loops, variables, or logic — we go straight into what makes C++ unique.

---

## ✅ What You’ll Find Here

* 🧩 **Source code** organized by topic
* 📂 **Practical projects**
* 📘 **Interactive `.ipynb` notebooks**
* 🔧 **CMake examples and best practices**
* 🚀 **Modern C++ (C++17/C++20)**

---

## 📚 Content Structure

* **01 — From C to C++, Compilers, CMake, .cpp, .hpp**

<!--
* **02 — Classes, Objects, and Modern OOP**
* **03 — RAII, Constructors, Move Semantics**
* **04 — Smart Pointers**
* **05 — Templates and Generic Programming**
* **06 — STL: Containers, Iterators, Algorithms**
* **07 — Real Project with CMake**
* **08 — Exceptions, Errors, and Best Practices**
* **09 — Multithreading and Performance**
* **10 — Project Organization and Deployment**
-->

---

## 🧠 C++ in `.ipynb` Notebooks

This repository uses **Jupyter notebooks** to run C++ interactively — using real compilation via *Cling/Xeus-Cling*.

This allows you to:

✅ Execute code in cells
✅ Test ideas quickly
✅ See results instantly
✅ Learn C++ with immediate feedback

---

## 💻 Running the Notebooks Locally in VS Code

### ✅ 1) Install VS Code and the required extensions

In VS Code, install:

* **Jupyter**
* **Jupyter Notebook Renderers**
* **Jupyter Keymap**
* **C/C++ (Microsoft)** (optional)

### ✅ 2) Install the C++ Jupyter environment (via mamba)

If you don’t have it yet, install Miniforge/Miniconda.

Then in the terminal:

```bash
mamba create -n cling
mamba activate cling
mamba install xeus-cling notebook -c conda-forge
```

This installs the C++ kernel for Jupyter.

### ✅ 3) Open the repository in VS Code from the terminal

```bash
mamba activate cling
code .
```

⚠️ Make sure to activate the environment **before** opening VS Code.

### ✅ 4) Open a `.ipynb` file and select the C++ kernel

Top right corner:

```
Select Kernel → C++17 (xeus-cling)
```

---

## 🛠️ Traditional Compilation (Optional)

You can also compile normally:

```bash
g++ main.cpp -std=c++17 -O2 -o app
./app
```

Or using CMake:

```bash
mkdir build
cd build
cmake ..
make
./app
```

---

## 🤝 Contributing

* Found a bug or have a suggestion? Open an **Issue**
* Want to add examples or challenges? Submit a **Pull Request**
* Technical discussions are welcome!

---

## 👨‍🏫 About the Author

Hey! I’m Caio. 👋
If you’d like to follow my work, access my social media, join the Discord server, or get in touch, I keep everything organized and always up to date at the link below:

👉 **[https://fromcaio.com/?section=socials](https://fromcaio.com/?section=socials)**

Feel free to reach out anytime!