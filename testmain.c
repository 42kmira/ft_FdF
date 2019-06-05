#include "./minilibx_macos/mlx.h"


void    draw_line(int x1, int y1, int x2, int y2, void *mlx, void *window)
{
    int cx = x2 - x1;
    int cy = y2 - y1;
    int i = x1;
    int j = y1;
    int sum;
    int move_y_by_one;

    sum = 0;
    while(i < x2)
    {
        sum += cy;

        move_y_by_one = sum / cx;

        if (move_y_by_one == 1 || move_y_by_one == -1)
        {
          if (move_y_by_one == 1)
          {
            sum -= cx;
            j++;
          }
          else
          {
            sum += cx;
            j--;
          }
        }
        i++;
        mlx_pixel_put(mlx, window, i, j, 0xFF0000);
    }
}
/*
void    draw_line2(int x1, int y1, int x2, int y2, void *mlx, void *window)
{
    int cx = x2 - x1;
    int cy = y2 - y1;
    int i = x1;
    int j = y1;
    int sum;
    int move_y_by_one;

    sum = 0;
    while(j < y2)
    {
        sum += cx;

        move_y_by_one = sum / cy;

        if (move_y_by_one > 0)
        {
            sum -= cy;
            i++;
        }
        j++;
        mlx_pixel_put(mlx, window, i, j, 0xFF0000);
    }
}
*/

int main(void)
{
  void *mlx;
  void *window;

  mlx = mlx_init();
  window = mlx_new_window(mlx, 1200, 1200, "Title");
  mlx_pixel_put(mlx, window, 66, 66, 0xFF0000);
  mlx_string_put(mlx, window, 20, 20, 0xFFFF00, "/\\------------------------------------------------/\\");
  mlx_string_put(mlx, window, 20, 40, 0xFFFF00, "\\/ Controls:                                      \\/");
  mlx_string_put(mlx, window, 20, 60, 0xFFFF00, "/\\    To Move            - up, down, left, right  /\\");
  mlx_string_put(mlx, window, 20, 80, 0xFFFF00, "\\/    To Zoom            - z, x                   \\/");
  mlx_string_put(mlx, window, 20, 100, 0xFFFF00, "/\\    To Change Color    - c                      /\\");
  mlx_string_put(mlx, window, 20, 120, 0xFFFF00, "\\/    To Change altitude - f, g                   \\/");
  mlx_string_put(mlx, window, 20, 140, 0xFFFF00, "/\\    To rotate           - 8, 2, 4, 6            /\\");
  mlx_string_put(mlx, window, 20, 160, 0xFFFF00, "\\/------------------------------------------------\\/");


  mlx_string_put(mlx, window, 60, 200, 0xFFFF00, "    /)");
  mlx_string_put(mlx, window, 60, 220, 0xFFFF00, "   (__)");
  mlx_string_put(mlx, window, 60, 240, 0xFFFF00, "  (____)");
  mlx_string_put(mlx, window, 60, 260, 0xFFFF00, " (______)");
  mlx_string_put(mlx, window, 60, 280, 0xFFFF00, "(________)");

  draw_line(300, 300, 800, 800, mlx, window);
  draw_line(300, 800, 800, 300, mlx, window);

  mlx_loop(mlx);
  return (0);
}