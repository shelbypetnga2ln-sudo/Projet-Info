#ifndef UTILS_H
#define UTILS_H
/console Windows/
void clear_screen(void);
void set_color(int text_color, int bg_color);
void reset_color(void);
void set_cursor_position(int row, int col);
void hide_cursor(void);
void show_cursor(void);
void sleep_ms(int ms);
enum{
    C_BLACK =0, C_BLUE =1, C_GREEN=2, C_CYAN=3, C_RED=4, C_MAGENTA=5,
    C_YELLOW=14, C_WHITE=15, C_GRAY=7
};

#endif // UTILS_H
