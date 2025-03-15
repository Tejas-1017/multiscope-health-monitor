@echo off
echo Setting up environment...
python -m venv venv
call venv\Scripts\activate.bat
pip install -r requirements.txt
python dashboard.py
pause
