# About
A collection of interpreters for some esoteric languages
[Esolang Wiki](https://esolangs.org/wiki/Main_Page)

# Interpreters
- `brainfuck.exe`       Intrepret brainf*ck files
    - Command Line: `./brainfuck.exe <file>.bf`
- `brainfuck_sub.exe`   Transform brainf\*uck-inspired languages, such as alpuck, into brainf\*ck files
    - Command Line: `./brainfuck_sub.exe <format> <src_file> <output_file>`
        - Format: format of file (if alphuck, enter "alphuck")
        - src_file: Source file to transpile
        - output_file: file to dump generated brainfu*k code into, which is able to be run by `brainfuck.exe`

# Supported Esolangs
- Brainf\*ck (`./brainfuck.exe`)
- Brainf\*ck substitutions (`./brainfuck_sub.exe`)
    - alphuck
    - binaryf*ck
    - blub
    - colonoscopy
    - ook
    - uwu
- Befunge (`./befunge.exe`)
