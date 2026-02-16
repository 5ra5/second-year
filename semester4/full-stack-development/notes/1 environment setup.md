Before diving into Django development, we need to set up a proper development environment. This involves three key components: a code editor, a Python virtual environment, and version control. Getting these right from the start will save you countless hours of frustration later.

## VS Code: Why Use an IDE?

### The Problem with Simple Tools

You _could_ write Python code in Notepad and run it from the terminal. So why do professional developers use tools like Visual Studio Code?

When working with frameworks like Django, you're not just writing a single Python file. A typical Django project contains:

- Dozens of Python files across multiple directories
- HTML templates with embedded template syntax
- CSS and JavaScript files
- Configuration files (settings, URLs, requirements)
- Database migrations

Try navigating all of that in Notepad while remembering which file contains which function. It becomes unmanageable very quickly.

### What VS Code Gives You

**Syntax Highlighting** - Code is colour-coded by type (functions, variables, strings, keywords). This makes code dramatically easier to read and helps you spot errors immediately. A missing quote mark becomes obvious when half your screen turns the wrong colour.

**IntelliSense (Autocomplete)** - Start typing a function name and VS Code suggests completions. It knows what methods are available on objects, what arguments functions expect, and can show you documentation inline. This means less time checking documentation and fewer typos.

**Integrated Terminal** - Run your Django server, execute management commands, and interact with Git without leaving the editor. Having everything in one window reduces context-switching.

**File Navigation** - Jump to any file with `Ctrl+P` (`Cmd+P` on Mac). Go to a function definition with `F12`. Find all references to a variable across your entire project. These features become essential as projects grow. [VS Code file navigation](https://code.visualstudio.com/docs/editing/editingevolved)

**Extensions** - VS Code has extensions for Python linting, Django template syntax, Git integration, and hundreds of other tools. The Python extension alone provides debugging, testing integration, and environment management.

**Error Detection** - With the right extensions, VS Code underlines errors before you even run your code. It catches typos, missing imports, and type mismatches as you type.

**Debugging** - Up to now, you've probably debugged code by adding `print()` statements everywhere, running your code, reading the output, adding more prints, and repeating until you find the problem. This works, but it's slow and tedious. VS Code has a built-in debugger that lets you pause your code at any line, inspect the value of every variable at that moment, and step through your code line by line. You can see exactly what's happening without modifying your code at all. No more guessing, no more print statements to clean up afterwards. [Debugging with VSCode](https://code.visualstudio.com/docs/debugtest/debugging)

**Run Configurations** - VS Code allows you to save different ways of running your project. For example, you might want to run your Django development server normally, or run it with the debugger attached, or run your test suite. Instead of remembering different terminal commands, you can save these as configurations and launch them with a single click. We'll explore run configurations in more detail later in the course when we set up debugging for Django. [VSCode Run Configurations](https://code.visualstudio.com/docs/debugtest/debugging-configuration)

### Recommended Extensions for This Course

Install these extensions in VS Code:

- **Python** (Microsoft) - Essential Python support
- **Pylance** - Enhanced Python language features
- **Django** - Django template syntax highlighting
- **GitLens** - Enhanced Git integration

To install: Open VS Code, press `Ctrl+Shift+X` (`Cmd+Shift+X` on Mac), search for the extension name, and click Install.

## Python Virtual Environments

### The Problem: Dependency Conflicts

Imagine this scenario:

- Project A requires Django 4.2
- Project B requires Django 3.2 (it uses features that were removed in 4.0)

If you install packages globally (system-wide), you can only have one version of Django installed at a time. Switching between projects would mean uninstalling and reinstalling different versions constantly.

Now multiply this by every package your projects use. It becomes impossible to manage.

### What is a Virtual Environment?

A virtual environment is an **isolated Python installation** for a specific project. When you create a virtual environment, Python creates a directory containing:

- Its own copy of the Python interpreter
- Its own `pip` package manager
- Its own `site-packages` directory for installed packages

Packages installed in a virtual environment are completely separate from your system Python and from other virtual environments. Project A can have Django 4.2 while Project B has Django 3.2, and they'll never interfere with each other.

### Creating a Virtual Environment

Navigate to your project directory and run:

```bash
python -m venv .venv
```

This creates a directory called `.venv` containing the virtual environment. The `.` prefix is a convention indicating it's a hidden/configuration directory.

Breaking down the command:

- `python -m venv` - Run the `venv` module
- `.venv` - Name of the directory to create (you can name it anything, but `.venv` is the convention)

### Activating the Virtual Environment

Creating the environment doesn't automatically use it. You need to **activate** it:

**Windows (Command Prompt):**

```bash
.venv\Scripts\activate
```

**Windows (PowerShell):**

```bash
.venv\Scripts\Activate.ps1
```

**Linux/macOS:**

```bash
source .venv/bin/activate
```

When activated, you'll see `(.venv)` at the start of your terminal prompt. This confirms you're working inside the virtual environment.

### Verifying Activation

After activation, check that pip points to the virtual environment:

```bash
pip --version
```

The path should include `.venv`. If it shows your system Python path instead, the environment isn't activated properly.

### Installing Packages

With the environment activated, install packages normally:

```bash
pip install django
```

This installs Django only in the virtual environment, not system-wide.
### Deactivating

When you're done working on a project:

```bash
deactivate
```

This returns you to your system Python environment.

### Why .venv and Not Something Else?

The name `.venv` is a widely-adopted convention:

- The `.` prefix hides it in Unix file listings (less clutter)
- It's immediately recognisable to other developers
- VS Code and other tools automatically detect it
- `.gitignore` templates typically include it by default

## Managing Dependencies with requirements.txt

### The Problem: "It Works on My Machine"

You've set up a virtual environment and installed Django. Your project works perfectly. Now your teammate clones the repository and tries to run it—but it crashes immediately because Django isn't installed on their machine.

Virtual environments are local to each machine and aren't shared through Git (they're in `.gitignore`, remember?). So how does your teammate know what packages to install?

### What is requirements.txt?

A `requirements.txt` file is a simple text file that lists all the Python packages your project depends on, along with their exact versions. It looks like this:

```
Django==5.0.1
pillow==10.2.0
requests==2.31.0
```

This file acts as a **recipe** for recreating your environment. Anyone with this file can install exactly the same packages you have.

### Why Exact Versions Matter

Notice the `==5.0.1` syntax—this specifies an exact version. Why not just list `Django` without a version?

Consider this scenario:

1. You develop your project with Django 5.0.1
2. Six months later, Django 5.1 is released with breaking changes
3. A new developer joins and runs `pip install Django`
4. They get Django 5.1, and the project breaks in mysterious ways

By pinning exact versions, everyone working on the project uses identical packages. This eliminates an entire category of bugs caused by version differences.

Version pinning also provides security benefits. In a **supply chain attack**, a malicious actor compromises a package and releases it as a new version. If your project automatically pulls the latest version, you could unknowingly install malware. By pinning to specific versions you've already vetted, you're protected until you consciously decide to upgrade.

- [The Ultralytics python package was the victim of a supply chain attack](https://blog.pypi.org/posts/2024-12-11-ultralytics-attack-analysis/)
- [So was termncolor](https://thehackernews.com/2025/08/malicious-pypi-and-npm-packages.html)
- [NPM the node package manager is routinely the victim of these attacks](https://www.cisa.gov/news-events/alerts/2025/09/23/widespread-supply-chain-compromise-impacting-npm-ecosystem)

### Generating requirements.txt

After installing your packages, generate the requirements file:

```bash
pip freeze > requirements.txt
```

The `pip freeze` command lists all installed packages with their versions. The `>` redirects this output into a file.

**Important:** Always run this command with your virtual environment activated. Otherwise, you'll capture your system-wide packages instead.

### Installing from requirements.txt

When someone clones your project, they run:
```bash
pip install -r requirements.txt
```
This installs every package listed in the file at the exact versions specified. The `-r` flag tells pip to read from a requirements file

### Keeping requirements.txt Updated

Whenever you install a new package, update your requirements file:

```bash
pip install some-new-package
pip freeze > requirements.txt
git add requirements.txt
git commit -m "Add some-new-package dependency"
```