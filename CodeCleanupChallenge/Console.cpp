#include "Console.h"


HANDLE Console::out = GetStdHandle(STD_OUTPUT_HANDLE);
WORD Console::defColors = Console::BackgroundColor() << 4 | Console::ForegroundColor();
HWND Console::hwnd = GetConsoleWindow();
const std::string Console::ESC = "\x1B";
int Console::windowWidth = 100, Console::windowHeight = 50;

void Console::ResizeWindow(int width, int height)
{
	windowWidth = width;
	windowHeight = height;
	std::cout << ESC << "[8;" << height << ";" << width << "t";
}
void Console::Reset()
{
	std::cout << ESC << "[0m";
}

void Console::Clear()
{
	std::cout << ESC << "[2J" << ESC << "[H"; //clears the screen and moves the cursor to the top-left
}


void Console::SetCursorLeft(int x)
{
	std::cout << ESC << "[" << x << "C";
}

void Console::Write(std::string message)
{
	std::cout << message;
}

void Console::Write(std::string message, WORD foreColor, WORD backColor)
{
	
	ForegroundColor(foreColor);
	BackgroundColor(backColor);
	std::cout << message;
	Reset();
}

void Console::WriteLine(std::string message)
{
	std::cout << message << std::endl;
}

void Console::WriteLine(std::string message, WORD foreColor, WORD backColor)
{
	ForegroundColor(foreColor);
	BackgroundColor(backColor);
	std::cout << message;
	Reset();
	std::cout << std::endl;
}

int Console::ConsoleFullWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	return info.srWindow.Right - info.srWindow.Left + 1;
}

int Console::ConsoleHalfWidth()
{
	return (int)(ConsoleFullWidth() * 0.5f);
}

int Console::ConsoleFullHeight()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	return info.srWindow.Bottom - info.srWindow.Top + 1;
}

int Console::ConsoleHalfHeight()
{
	return (int)(ConsoleFullHeight() * 0.5f);
}

void Console::SetWindowSize(SHORT columns, SHORT rows)
{
	COORD c = GetLargestConsoleWindowSize(out);
	if (columns < 1 || columns > c.X)
		columns = c.X;
	if (rows < 1 || rows > c.Y)
		rows = c.Y;

	SMALL_RECT dim = { 0, 0, columns - 1, rows - 1 };
	SetConsoleWindowInfo(out, TRUE, &dim);
}

int Console::CursorLeft()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	return info.dwCursorPosition.X;
}

int Console::CursorTop()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	return info.dwCursorPosition.Y;
}

void Console::SetCursorPosition(SHORT left, SHORT top)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);

	left = max(left, 0);
	left = min(left, info.dwSize.X - 1);
	top = max(top, 0);
	top = min(top, info.dwSize.Y - 1);

	COORD cp = { left, top, };
	SetConsoleCursorPosition(out, cp);
}

void Console::CursorVisible(bool visible)
{
	CONSOLE_CURSOR_INFO curs;
	GetConsoleCursorInfo(out, &curs);
	if (curs.bVisible == TRUE && visible || curs.bVisible == FALSE && !visible)
		return;
	curs.bVisible = (visible) ? TRUE : FALSE;
	SetConsoleCursorInfo(out, &curs);
}


void Console::Lock(bool lock)
{
	
	LockWindowUpdate(lock ? hwnd : nullptr);
	
}

void Console::FlushKeys()
{
	for (int i = 0; i < 256; ++i) GetAsyncKeyState(i);
	while (_kbhit()) _getch();
}

void Console::Show(wchar_t symbol)
{
	std::wcout << symbol;
}

void Console::Show(int x, int y, wchar_t symbol)
{
	static bool imbued;
	if (!imbued)
	{
		std::wcout.imbue(std::locale(".OCP"));
		imbued = true;
	}
	SetCursorPosition(x, y);
	Show(symbol);
}

void Console::PrintCentered(SHORT left, SHORT top, std::string message)
{
	SetCursorPosition(left - (int)(message.length() * 0.5f), top);
	std::cout << message;
}

void Console::DrawBox(int left, int top, int width, int height, bool dbl)
{
	wchar_t const* SingleLine = L"┌─┐│└┘",
		* DoubleLine = L"╔═╗║╚╝",
		* Set = dbl ? DoubleLine : SingleLine;

	Show(left, top, Set[0]);
	for (int col = 0; col < width - 2; col++)
		Show(Set[1]);
	Show(Set[2]);

	int x = left + width - 1, y = top + 1;
	for (int row = 0; row < height - 2; row++, y++)
	{
		Show(left, y, Set[3]);
		Show(x, y, Set[3]);
	}

	y = top + height - 1;
	Show(left, y, Set[4]);
	for (int col = 0; col < width - 2; col++)
		Show(Set[1]);
	Show(Set[5]);
}

//void Console::DisplayMenu()
//{
//	int top = (int)(ConsoleFullHeight() * 0.25f) - 1;
//
//	std::string menu_binary = "1. Binary";
//	std::string menu_hexadecimal = "2. Hexadecimal";
//	std::string menu_octal = "3. Octal";
//	std::string menu_esc = GetKeyBindName(KeyEscape) + ": Exit";
//
//	PrintCentered(ConsoleHalfWidth(), top + (int)(ConsoleHalfHeight() * 0.25), labTitle);
//	PrintCentered(ConsoleHalfWidth(), CursorTop() + 3, menu_binary);
//	PrintCentered(ConsoleHalfWidth(), CursorTop() + 2, menu_hexadecimal);
//	PrintCentered(ConsoleHalfWidth(), CursorTop() + 2, menu_octal);
//	PrintCentered(ConsoleHalfWidth(), CursorTop() + 2, menu_esc);
//}

WORD Console::ForegroundColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	return info.wAttributes & 0x0F;
}

void Console::ForegroundColor(WORD attr)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	SetConsoleTextAttribute(out, info.wAttributes & 0xF0 | attr);
}

WORD Console::BackgroundColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	return (info.wAttributes & 0xF0) >> 4;
}

void Console::BackgroundColor(WORD attr)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	SetConsoleTextAttribute(out, info.wAttributes & 0x0F | attr << 4);
}

void Console::ResetColor()
{
	SetConsoleTextAttribute(out, defColors);
}

std::string Console::GetKeyBindName(KeyBinds key)
{
	std::string retVal;

	switch (key)
	{
	case KeyBinds::Key_A: retVal = "A";	 break;
	case KeyBinds::Key_B: retVal = "B";	 break;
	case KeyBinds::Key_C: retVal = "C";	 break;
	case KeyBinds::Key_D: retVal = "D";	 break;
	case KeyBinds::Key_E: retVal = "E";	 break;
	case KeyBinds::Key_F: retVal = "F";	 break;
	case KeyBinds::Key_G: retVal = "G";	 break;
	case KeyBinds::Key_H: retVal = "H";	 break;
	case KeyBinds::Key_I: retVal = "I";	 break;
	case KeyBinds::Key_J: retVal = "J";	 break;
	case KeyBinds::Key_K: retVal = "K";	 break;
	case KeyBinds::Key_L: retVal = "L";	 break;
	case KeyBinds::Key_M: retVal = "M";	 break;
	case KeyBinds::Key_N: retVal = "N";	 break;
	case KeyBinds::Key_O: retVal = "O";	 break;
	case KeyBinds::Key_P: retVal = "P";	 break;
	case KeyBinds::Key_Q: retVal = "Q";	 break;
	case KeyBinds::Key_R: retVal = "R";	 break;
	case KeyBinds::Key_S: retVal = "S";	 break;
	case KeyBinds::Key_T: retVal = "T";	 break;
	case KeyBinds::Key_U: retVal = "U";	 break;
	case KeyBinds::Key_V: retVal = "V";	 break;
	case KeyBinds::Key_W: retVal = "W";	 break;
	case KeyBinds::Key_X: retVal = "X";	 break;
	case KeyBinds::Key_Y: retVal = "Y";	 break;
	case KeyBinds::Key_Z: retVal = "Z";	 break;

	case KeyBinds::Key_0: retVal = "0";	 break;
	case KeyBinds::Key_1: retVal = "1";	 break;
	case KeyBinds::Key_2: retVal = "2";	 break;
	case KeyBinds::Key_3: retVal = "3";	 break;
	case KeyBinds::Key_4: retVal = "4";	 break;
	case KeyBinds::Key_5: retVal = "5";	 break;
	case KeyBinds::Key_6: retVal = "6";	 break;
	case KeyBinds::Key_7: retVal = "7";	 break;
	case KeyBinds::Key_8: retVal = "8";	 break;
	case KeyBinds::Key_9: retVal = "9";	 break;

	case KeyBinds::Key_F1: retVal = "F1"; break;
	case KeyBinds::Key_F2: retVal = "F2"; break;
	case KeyBinds::Key_F3: retVal = "F3"; break;
	case KeyBinds::Key_F4: retVal = "F4"; break;
	case KeyBinds::Key_F5: retVal = "F5"; break;
	case KeyBinds::Key_F6: retVal = "F6"; break;
	case KeyBinds::Key_F7: retVal = "F7"; break;
	case KeyBinds::Key_F8: retVal = "F8"; break;
	case KeyBinds::Key_F9: retVal = "F9"; break;
	case KeyBinds::Key_F10: retVal = "F10";	 break;
	case KeyBinds::Key_F11: retVal = "F11";	 break;
	case KeyBinds::Key_F12: retVal = "F12";	 break;

	case KeyBinds::Key_Space: retVal = "Space"; break;
	case KeyBinds::Key_Backspace: retVal = "ESC"; break;
	case KeyBinds::Key_Tab: retVal = "Tab"; break;
	case KeyBinds::Key_Enter: retVal = "Enter"; break;
	case KeyBinds::Key_Shift: retVal = "Shift"; break;
	case KeyBinds::Key_Ctrl: retVal = "Ctrl"; break;
	case KeyBinds::Key_Alt: retVal = "Alt"; break;
	case KeyBinds::Key_Escape: retVal = "Escape"; break;
	case KeyBinds::Key_Left: retVal = "<"; break;
	case KeyBinds::Key_Up: retVal = "Up"; break;
	case KeyBinds::Key_Right: retVal = ">"; break;
	case KeyBinds::Key_Down: retVal = "Down"; break;
	default: retVal = "Unknown Key"; break;
	}

	return retVal;
}



