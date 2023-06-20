/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:40:55 by rcastano          #+#    #+#             */
/*   Updated: 2023/06/20 10:48:04 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_so_long.h"

//cerrar la ventana        pero el proceso no termina como con control + c
// que es un floodfill
//mapa validarlo procesar texto
//game loop
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* void floodfill()
{

} */

/* void reed_map(void)
{
	int fd;

	fd = open("map.ber", O_RDONLY);
	get_next_line(fd);
	//comrpobar que el mapa sea válido

} */

int	key_hook(int key, t_vars	*vars)
{
	if (key == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return(0);
}

int	read_from_image(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./sprites";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);

	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "patata");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (1);
	}
	img.img =  mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int test = 5;
	while(test < 100)
	{
		my_mlx_pixel_put(&img, test, 5, 0x00FF0000);
		test++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	//mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx); //mlx_loop_hook(mlx, render_next_frame, YourStruct);
	



	//mlx_destroy_display(vars.mlx); no funciona en mac
	free(vars.mlx);
	return (0);
}

/*
	void DrawCircle(int x, int y, int r, int color)
{
      static const double PI = 3.1415926535;
      double i, angle, x1, y1;

      for(i = 0; i < 360; i += 0.1)
      {
            angle = i;
            x1 = r * cos(angle * PI / 180);
            y1 = r * sin(angle * PI / 180);
            putpixel(x + x1, y + y1, color);
      }
}
*/

/*
#include<iostream> 
using namespace std; 
// Dimentions of myScreen. You may change
#define M 8
#define N 8
  
// A recursive function to replace 
// previous color 'currColor' at  '(x, y)'  
// and all surrounding pixels of (x, y) 
// with new color 'newColor'
void floodFill(int myScreen[][N], int x, int y, int currColor, int newColor) 
{ 
    // Base cases 
    if (x < 0 || x >= M || y < 0 || y >= N) 
        return; 
    if (myScreen[x][y] != currColor) 
        return; 
    if (myScreen[x][y] == newColor) 
        return; 
  
    // Replace the color at cell (x, y) 
    myScreen[x][y] = newColor; 
  
    // Recursively call for north, east, south and west 
    floodFill(myScreen, x+1, y, currColor, newColor); 
    floodFill(myScreen, x-1, y, currColor, newColor); 
    floodFill(myScreen, x, y+1, currColor, newColor); 
    floodFill(myScreen, x, y-1, currColor, newColor); 
} 
  
// It mainly finds the previous color on (x, y) and 
// calls floodFill() 
void findColor(int myScreen[][N], int x, int y, int newColor) 
{ 
    int currColor = myScreen[x][y]; 
    floodFill(myScreen, x, y, currColor, newColor); 
} 
  
// Driver program to test above function 
int main() 
{ 
    int myScreen[M][N] = 
                    {
                      {3, 2, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}, 
                     }; 
    int x = 4, y = 4, newColor = 3; 
    findColor(myScreen, x, y, newColor); 
  
    cout << "Updated myScreen : \n"; 
    
    //printing screen
    for (int i=0; i<M; i++) 
    { 
        for (int j=0; j<N; j++) 
           cout << myScreen[i][j] << " "; 
        cout << endl; 
    } 
    return 0;
} 
*/