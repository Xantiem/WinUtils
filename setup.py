from setuptools import setup, Extension

module = Extension(
	"WinUtils", 
	sources = ["main.c"],
        libraries = ["user32"]
)

setup (
	name = "WinUtils",
	version = "1.0",
        description = "A module to provide simplified system calls on Windows",
        author = "Simon",
        url = "https://github.com/Simon3335/WinUtils",
        license = 'MIT',
        python_requires = '>=3',
        data_files = ["LICENSE.txt"], 
	ext_modules = [module])
