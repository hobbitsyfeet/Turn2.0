call ./env/Scripts/activate.bat
call "./env/Scripts/pip.exe" install -r requirments.txt
call cd ./Turn/
call pyinstaller --onefile main.py
call cp ./dist/main.exe ../
call cd ../
call mv main.exe Turn.exe
