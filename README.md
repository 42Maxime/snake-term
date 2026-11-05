# snake-term

A terminal Snake in C. The board is 42 columns wide. Eat 42 snacks to win.

Start in the folder containing `snake.c`. Use an interactive terminal at least 46 columns wide and 21 rows tall.

## Windows 10 / 11

Install MSYS2. Open **MSYS2 UCRT64** and install GCC:

```sh
pacman -S --needed mingw-w64-ucrt-x86_64-gcc
```

Open **PowerShell** in the project folder. With the default MSYS2 installation:

```powershell
$env:Path = "C:\msys64\ucrt64\bin;" + $env:Path
gcc -std=c99 -Wall -Wextra -Werror snake.c move.c draw.c error.c terminal_win.c -o snake.exe
.\snake.exe
```

If you installed MSYS2 elsewhere, adjust the first line. Run the game directly in PowerShell or Windows Terminal so it can read the keyboard.

## Linux

On Ubuntu or Debian, install the compiler and Make if needed:

```sh
sudo apt install build-essential
```

On other distributions, install a C compiler and GNU Make with your package manager. Then build and play:

```sh
make
./snake
```

## macOS

Open Terminal. If you don't already have the Command Line Tools, run:

```sh
xcode-select --install
```

Once installation finishes, build with Apple Clang and play:

```sh
make CC=clang
./snake
```

## Controls

Use lowercase **WASD** or **ZQSD**. The first movement key starts the game.
You are `@`; eat the pink `*` to grow. Hitting a wall or your body ends the run.
Press **x** to quit. Run the same launch command to play again.

## Source

`move.c` holds the board and movement rules. The first point in the body array is the head.
`terminal.c` (Unix) or `terminal_win.c` (Windows) handles the keyboard and restores terminal settings when the game exits.

GitHub [@42Maxime](https://github.com/42Maxime) · MIT License
