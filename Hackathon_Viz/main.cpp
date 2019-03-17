#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "calcBFS.h"
#include "util.h"

constexpr auto WIDTH = 900;
constexpr auto HEIGHT = 900;


std::vector<std::pair<int, int> > pt;
std::vector<std::pair<int, int> > path;

void draw(int n) {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;
	sf::Font font;
	font.loadFromFile("./fonts/arial.ttf");

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Hackathon_Viz", sf::Style::Default, settings);;

	std::vector<sf::RectangleShape> line;
	std::vector<sf::CircleShape> point;
	std::vector<sf::RectangleShape> route;
	std::vector<sf::Text> coord;
	

	std::vector<sf::CircleShape> curP;

	int space = 600 / n;
	for (int i = space; i < 900; i += space) {
		sf::RectangleShape l(sf::Vector2f(900 - space, 3));
		l.setPosition(space, i);
		l.setFillColor(sf::Color::Black);

		sf::RectangleShape r(sf::Vector2f(3, 900 - space));
		r.setPosition(i, space);
		r.setFillColor(sf::Color::Black);

		line.push_back(l);
		line.push_back(r);
		
		sf::Text tl(std::to_string(i/space-1), font);
		tl.setPosition(space-25, i-15);
		tl.setCharacterSize(20);
		tl.setStyle(sf::Text::Bold);
		tl.setFillColor(sf::Color::Black);

		if (i / space - 1) {
			sf::Text tr(std::to_string(i / space - 1), font);
			tr.setCharacterSize(20);
			tr.setPosition(i - 5, space - 25);
			tr.setStyle(sf::Text::Bold);
			tr.setFillColor(sf::Color::Black);
			coord.push_back(tr);
		}

		coord.push_back(tl);
	}

	for (auto p : pt) {
		int y = p.first + 1;
		int x = p.second + 1;
		sf::CircleShape c(10);
		c.setPosition(space * x - 9, space * y - 9);
		if (p == *pt.begin()) c.setFillColor(sf::Color::Magenta);
		else c.setFillColor(sf::Color::Red);
		point.push_back(c);
	}

	int ty = path[0].first + 1;
	int tx = path[0].second + 1;
	sf::CircleShape c(8);
	c.setPosition(space*tx - 7, space*ty - 7);
	c.setFillColor(sf::Color::Yellow);
	curP.push_back(c);

	for (int i = 1; i < path.size(); ++i) {
		int sy = path[i - 1].first + 1;
		int sx = path[i - 1].second + 1;
		int ty = path[i].first + 1;
		int tx = path[i].second + 1;

		if (sx == tx) {
			sf::RectangleShape l(sf::Vector2f(6, space));
			l.setPosition(space * sx, space * std::min(sy, ty));
			l.setFillColor(sf::Color::Blue);
			route.push_back(l);

		}
		if (sy == ty) {
			sf::RectangleShape l(sf::Vector2f(space, 6));
			l.setPosition(space * std::min(sx, tx), space * sy);
			l.setFillColor(sf::Color::Blue);
			route.push_back(l);
		}

		sf::CircleShape c(8);
		c.setPosition(space*tx - 7, space*ty - 7);
		c.setFillColor(sf::Color::Yellow);
		curP.push_back(c);
	}

	int k = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::N) {
					k++;
					k = std::min(k, (int)curP.size()-1);
				}
				if (event.key.code == sf::Keyboard::R)
					k = 0;
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		for (int i = 0; i < line.size(); ++i) {
			window.draw(line[i]);
			if(i) window.draw(coord[i-1]);
		}
		for (int i = 0; i < route.size() && i < k; ++i) {
			window.draw(route[i]);
		}
		for (int i = 0; i < point.size(); ++i) {
			window.draw(point[i]);
		}
		window.draw(curP[k]);
		window.display();
	}
}


void readF(const char * infile, const char* outfile, int &max) {

	int n, m, sx, sy, k;
	freopen(infile, "r", stdin);
	scanf("%d%d%d%d%d", &n, &m, &sx, &sy, &k);
	max = std::max(n, m);
	pt.push_back({ sx, sy });

	//printf("%d %d\n", n, m);
	for (int i = 0; i < k; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		pt.push_back({ u, v });
	}

	for (int i = 0; i < n*m; ++i) {
		int u, v, g, r, t;
		scanf("%d%d%d%d%d", &u, &v, &g, &r, &t);
		map[u][v] = { g, r, t, 0 };
	}

	freopen(outfile, "r", stdin);

	long long ans;
	scanf("%lld", &ans);
	int u, v;
	while (~scanf("%d%d", &u, &v)) {
		path.push_back({ u, v });
	}
}


void initDraw() {

	int cnt = 18;
	std::string infile = "./data/inputs_sat/input_" + std::to_string(cnt);
	infile += ".txt";
	std::string outfile = "./data/output_sat/output_" + std::to_string(cnt);
	outfile += ".txt";

	int n;
	readF(infile.c_str(), outfile.c_str(), n);
	draw(n);

}


void run() {
	for (int i = 1; i <= 10; ++i) {
		std::vector<std::vector<std::pair<int, int> > > path;
		ULL ans = 0;
		std::string infile = "./data/input_sun/input_" + std::to_string(i);
		infile += ".txt";
		std::string outfile = "./data/output_sun/output_" + std::to_string(i);
		outfile += ".txt";
		getPath(infile.c_str(), outfile.c_str(), ans, path);
	}
}

int main() {
	//run();

	initDraw();
}