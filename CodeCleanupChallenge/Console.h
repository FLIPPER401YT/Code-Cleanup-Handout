#pragma once
#include <string>
#include <conio.h>
#include <cstdlib>

#include <stdio.h>
#include <tchar.h>
#include <iomanip>

#include <iostream>
#include <Windows.h>
#include <sstream>

enum class KeyBinds : byte
{
    // Alphabet keys
    Key_A = 0x41,  // 'A' key
    Key_B = 0x42,  // 'B' key
    Key_C = 0x43,  // 'C' kezy
    Key_D = 0x44,  // 'D' key
    Key_E = 0x45,  // 'E' key
    Key_F = 0x46,  // 'F' key
    Key_G = 0x47,  // 'G' key
    Key_H = 0x48,  // 'H' key
    Key_I = 0x49,  // 'I' key
    Key_J = 0x4A,  // 'J' key
    Key_K = 0x4B,  // 'K' key
    Key_L = 0x4C,  // 'L' key
    Key_M = 0x4D,  // 'M' key
    Key_N = 0x4E,  // 'N' key
    Key_O = 0x4F,  // 'O' key
    Key_P = 0x50,  // 'P' key
    Key_Q = 0x51,  // 'Q' key
    Key_R = 0x52,  // 'R' key
    Key_S = 0x53,  // 'S' key
    Key_T = 0x54,  // 'T' key
    Key_U = 0x55,  // 'U' key
    Key_V = 0x56,  // 'V' key
    Key_W = 0x57,  // 'W' key
    Key_X = 0x58,  // 'X' key
    Key_Y = 0x59,  // 'Y' key
    Key_Z = 0x5A,  // 'Z' key

    // Numeric keys
    Key_0 = 0x30,  // '0' key
    Key_1 = 0x31,  // '1' key
    Key_2 = 0x32,  // '2' key
    Key_3 = 0x33,  // '3' key
    Key_4 = 0x34,  // '4' key
    Key_5 = 0x35,  // '5' key
    Key_6 = 0x36,  // '6' key
    Key_7 = 0x37,  // '7' key
    Key_8 = 0x38,  // '8' key
    Key_9 = 0x39,  // '9' key

    // Function keys
    Key_F1 = 0x70,
    Key_F2 = 0x71,
    Key_F3 = 0x72,
    Key_F4 = 0x73,
    Key_F5 = 0x74,
    Key_F6 = 0x75,
    Key_F7 = 0x76,
    Key_F8 = 0x77,
    Key_F9 = 0x78,
    Key_F10 = 0x79,
    Key_F11 = 0x7A,
    Key_F12 = 0x7B,

    // Special keys
    Key_Backspace = 0x08,   // Backspace key
    Key_Tab = 0x09,         // Tab key
    Key_Enter = 0x0D,       // Enter key
    Key_Shift = 0x10,       // Shift key
    Key_Ctrl = 0x11,        // Ctrl key
    Key_Alt = 0x12,         // Alt key
    Key_Escape = 0x1B,      // Escape key
    Key_Space = 0x20,       // Space bar
    Key_Left = 0x25,        // Left arrow
    Key_Up = 0x26,          // Up arrow
    Key_Right = 0x27,       // Right arrow
    Key_Down = 0x28,        // Down arrow

    // Additional keys
    Key_Insert = 0x2D,
    Key_Delete = 0x2E,
    Key_Home = 0x24,
    Key_End = 0x23,
    Key_PageUp = 0x21,
    Key_PageDown = 0x22,
    Key_NumLock = 0x90,
    Key_CapsLock = 0x14
};

//enum ConsoleColor
//{
//    Black,
//    Red,
//    Green,
//    Yellow,
//    Blue,
//    Magenta,
//    Cyan,
//    White,
//    Default = 9
//};

class Console
{
    // Colors - can be used as Foreground or Background

    enum class RunType : byte
    {
        MainMenu,
        Map,
        Inventory,
        HexMenu,
        ExitMenu
    };


    static HANDLE out;
    static WORD defColors;
    static HWND hwnd;

public:
    std::string labTitle;

    enum class ConsoleColor : byte
    {
        Black = 0,
        DarkBlue = FOREGROUND_BLUE,
        DarkGreen = FOREGROUND_GREEN,
        DarkCyan = FOREGROUND_GREEN | FOREGROUND_BLUE,
        DarkRed = FOREGROUND_RED,
        DarkMagenta = FOREGROUND_RED | FOREGROUND_BLUE,
        DarkYellow = FOREGROUND_RED | FOREGROUND_GREEN,
        Gray = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
        DarkGray = FOREGROUND_INTENSITY,
        Blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
        Green = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
        Cyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
        Red = FOREGROUND_RED | FOREGROUND_INTENSITY,
        Magenta = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
        Yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
        White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    };


    // Change Keybinds Here
    static const KeyBinds KeyEnter = KeyBinds::Key_Enter;
    static const KeyBinds KeyRight = KeyBinds::Key_Left;
    static const KeyBinds KeyLeft = KeyBinds::Key_Right;
    static const KeyBinds KeyUp = KeyBinds::Key_Up;
    static const KeyBinds KeyDown = KeyBinds::Key_Down;
    static const KeyBinds KeyEscape = KeyBinds::Key_Escape;



    static void ResizeWindow(int width, int height);
    static int GetWindowWidth() { return windowWidth; }
    static int GetWindowHeight() { return windowHeight; }
    static void SetCursorLeft(int x);
    static void Reset();
    static void Clear();

    static void Write(std::string message);
    static void Write(std::string message, WORD foreColor, WORD backColor);
    static void WriteLine(std::string message);
    static void WriteLine(std::string message, WORD foreColor, WORD backColor);

#pragma region Console Dimensions
    // Get the full width of the window in cells (characters)
    static int ConsoleFullWidth();

    // Get the half width of the window in cells (characters)
    static int ConsoleHalfWidth();

    // Get the full height of the window in cells (characters)
    static int ConsoleFullHeight();

    // Get the half height of the window in cells (characters)
    static int ConsoleHalfHeight();

    // Change the size of the window
    static void SetWindowSize(SHORT columns, SHORT rows);
#pragma endregion

#pragma region Cursor
    // Get the current column of the cursor
    static int CursorLeft();

    // Get the current row of the cursor
    static int CursorTop();

    // Change the position of the cursor
    static void SetCursorPosition(SHORT left, SHORT top);

    // Set the visibility of the cursor
    static void CursorVisible(bool visible);
#pragma endregion

    // For animation and/or to reduce flickering
    static void Lock(bool lock);

    // Prevent cin and GetAsyncKeyState() from seeing each other's input.
    static void FlushKeys();

    // Display a Unicode symbol.
    static void Show(wchar_t symbol);

    static void Show(int x, int y, wchar_t symbol);

    // Prints in the center best as it can be
    static void PrintCentered(SHORT left, SHORT top, std::string message);

    // Display a rectangle in the window.
    static void DrawBox(int left, int top, int width, int height, bool dbl);

    static bool WasRightPressed() { return GetAsyncKeyState((int)Console::KeyRight); }
    static bool WasLeftPressed() { return GetAsyncKeyState((int)Console::KeyLeft); }
    static bool WasUpPressed() { return GetAsyncKeyState((int)Console::KeyUp); }
    static bool WasDownPressed() { return GetAsyncKeyState((int)Console::KeyDown); }
    static bool WasEscapePressed() { return GetAsyncKeyState((int)Console::KeyEscape); }
    static bool WasEnterPressed() { return GetAsyncKeyState((int)Console::KeyEnter); }


    // Displays the a given menu to the user
    //void DisplayMenu();

#pragma region Color 
    // Get the current foreground color
    static WORD ForegroundColor();

    // Change the foreground color
    static void ForegroundColor(WORD attr);

    // Get the current background color
    static WORD BackgroundColor();

    // Change the background color
    static void BackgroundColor(WORD attr);

    // Set the colors back to the defaults (usually gray on black)
    static void ResetColor();
#pragma endregion

    std::string GetKeyBindName(KeyBinds key);

private:
    static const std::string ESC;

    static int windowWidth, windowHeight;

    
};



