#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <Windows.h>

using namespace std;


const int width = 375;                             
const int height = 375;
bool running ;

SDL_Event ev;
SDL_Window *win = nullptr;
SDL_Renderer *renderer = nullptr;

SDL_Texture *background = nullptr;
SDL_Rect backgroundRect;
SDL_Texture *knot = nullptr;
SDL_Texture *cross = nullptr;
SDL_Rect positionRect[3][3];


int board[3][3];
bool firstPerson;


SDL_Texture *loadTexture(string filePath, SDL_Renderer *renderTarget);
void init();
void update(SDL_Event x);
void draw(SDL_Renderer *renderTarget);
void input(SDL_Event xp);
void logic();

void resetBoard()
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
			board[y][x] = 0;
	}
}


int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	init();

	MessageBox(NULL, "Welcome to tic tack toe 1.0 \n click over the cell you want to mark.\n first preson gets cross and the second person gets knot\n","About",NULL);
	win = SDL_CreateWindow("Tic Tac toe 1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	background = loadTexture("image/box.jpg", renderer);
	knot = loadTexture("image/knot.png", renderer);
	cross = loadTexture("image/cross.png", renderer);

	SDL_SetRenderDrawColor(renderer, 240, 240, 245, 225);
	while (running)
	{
		update(ev);
		draw(renderer);
		logic();

	}

	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(knot);
	SDL_DestroyTexture(cross);

	win = nullptr;
	renderer = nullptr;
	background = nullptr;
	knot = nullptr;
	cross = nullptr;

	IMG_Quit();
	SDL_Quit();

	return 0;
}


SDL_Texture *loadTexture(string filePath, SDL_Renderer *renderTarget)
{
	SDL_Texture *texture = nullptr;
	SDL_Surface *surface = IMG_Load(filePath.c_str());
	texture = SDL_CreateTextureFromSurface(renderTarget, surface);
	SDL_FreeSurface(surface);
	surface = nullptr;
	return texture;
}

void init()
{
	running = true;
	firstPerson = true;

	backgroundRect.h = height;
	backgroundRect.w = width;
	backgroundRect.x = 0;
	backgroundRect.y = 0;

	resetBoard();
	
	
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (j == 0)
				positionRect[j][i].y = 0;
			if (j == 1)
				positionRect[j][i].y = 125;
			if (j == 2)
				positionRect[j][i].y = 125*2;

			if (i == 0)
				positionRect[j][i].x = 0;
			if (i == 1)
				positionRect[j][i].x = 125;
			if (i == 2)
				positionRect[j][i].x = 125*2;

			positionRect[j][i].h = positionRect[j][i].w = 125;
			
		}
	}
}


void update(SDL_Event x)
{
	while (SDL_PollEvent(&x))
	{
		if (x.type == SDL_QUIT)
			running = false;
		input(x);
	}
}


void input(SDL_Event xp)
{
	int xPos, yPos;
	if (xp.type == SDL_MOUSEBUTTONDOWN)
	{
		xPos = xp.button.x;
		yPos = xp.button.y;

			for (int y = 0; y < 3; y++)
			{
				for (int x = 0; x < 3; x++)
				{
					if ((xPos>positionRect[y][x].x) && (xPos < positionRect[y][x].x + positionRect[y][x].w) && (yPos>positionRect[y][x].y) && (yPos < positionRect[y][x].y + positionRect[y][x].h))
					{
						if (board[y][x] == 0)
						{
							if (firstPerson == true)
							{
								board[y][x] = 1;
								firstPerson = false;
							}
							else if (firstPerson == false)
							{
								board[y][x] = 2;
								firstPerson = true;
							}
								
						}
					}
				}
			}
	}
	
}


void draw(SDL_Renderer *renderTarget)
{
	SDL_RenderClear(renderTarget);
	SDL_RenderCopy(renderTarget, background, NULL, &backgroundRect);
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (board[y][x] == 1)
				SDL_RenderCopy(renderTarget, cross, NULL, &positionRect[y][x]);
			else if (board[y][x] == 2)
				SDL_RenderCopy(renderTarget, knot, NULL, &positionRect[y][x]);
		}
	}
	SDL_RenderPresent(renderTarget);
}

void logic()
{
	if (board[0][0] != 0 && board[0][1] != 0 && board[0][2] != 0 && board[1][0] != 0 && board[1][1] != 0 && board[1][2] != 0 && board[2][0] != 0 && board[2][1] != 0 && board[2][2] != 0)
	{
		MessageBox(NULL, "Game over, \n it's a draw", "DRAW!", NULL);
		resetBoard();
	}
	//************************* player1 victory**************************************
	if (board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1)
	{
		MessageBox(NULL, "first player wins! ", "Victory", NULL);
		resetBoard();
	}
	if (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1)
	{
		MessageBox(NULL, "cross player wins! ", "Victory", NULL);
		resetBoard();
	}
	if (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1)
	{
		MessageBox(NULL, "cross player wins! ", "Victory", NULL);
		resetBoard();
	}
	if (board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1)
	{
		MessageBox(NULL, "cross player wins! ", "Victory", NULL);
		resetBoard();
	}
	if (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1)
	{
		MessageBox(NULL, "cross player wins! ", "Victory", NULL);
		resetBoard();
	}
	if (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1)
	{
		MessageBox(NULL, "cross player wins! ", "Victory", NULL);
		resetBoard();
	}
	if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1)
	{
		MessageBox(NULL, "cross player wins! ", "Victory", NULL);
		resetBoard();
	}
	if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1)
	{
		MessageBox(NULL, "cross player wins! ", "Victory", NULL);
		resetBoard();
	}

	//************************* player2 victory**************************************
	if (board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 2)
	{
		MessageBox(NULL, "knot player wins! ", "Victory", NULL);
		resetBoard();
	}
	if (board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 2)
	{
		MessageBox(NULL, "knot player wins! ", "Victory", NULL);
		resetBoard();
	}
	if (board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 2)
	{
		MessageBox(NULL, "knot player wins! ", "Victory", NULL);
		resetBoard();
	}
	if (board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 2)
	{
		MessageBox(NULL, "knot player wins! ", "Victory", NULL);
		resetBoard();
	}
	if (board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 2)
	{
		MessageBox(NULL, "knot player wins! ", "Victory", NULL);
		resetBoard();
	}
	if (board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 2)
	{
		MessageBox(NULL, "knot player wins! ", "Victory", NULL);
		resetBoard();
	}
	if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2)
	{
		MessageBox(NULL, "knot player wins! ", "Victory", NULL);
		resetBoard();
	}
	if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2)
	{
		MessageBox(NULL, "knot player wins! ", "Victory", NULL);
		resetBoard();
	}
}