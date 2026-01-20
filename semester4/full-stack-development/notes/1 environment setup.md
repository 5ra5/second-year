
## Creating a virtual environment

Navigate to project directory and run:
```bash
python -m venv .venv
```

## Activating the virtual environment

Linux
```bash
source .venv/bin/activate
```

Windows (PowerShell)
```bash
.venv\Scripts\Activate.ps1
```

You should now see `(.venv)` at the start of the terminal prompt

## Verifying activation

```bash
pip --version
```

The path should include `.venv`

## Installing packages

```bash
pip install django
```

## Deactivating

```bash
deactivate
```

## Generating requirements.txt

```bash
pip freeze > requirements.txt
```

## Installing from requirements.txt

```bash
pip install -r requirements.txt
```

## Keeping requirements.txt updated

```bash
pip install some-new-package
pip freeze > requirements.txt
git add requirements.txt
git commit -m "Add some-new-package dependency"
```