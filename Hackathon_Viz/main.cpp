#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "calcBFS.h"
#include "util.h"
typedef long long ULL;

constexpr auto WIDTH = 900;
constexpr auto HEIGHT = 900;

template<class Point, class Vector>
void draw(Point pt, Vector path) {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;
	sf::Font font;
	font.loadFromFile("./fonts/arial.ttf");

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Hackathon_Viz", sf::Style::Default, settings);;

	std::vector<sf::RectangleShape> line;
	std::vector<sf::CircleShape> point;
	std::vector<sf::RectangleShape> route;

	for (int i = 1; i < 900; i += 100) {
		sf::RectangleShape l(sf::Vector2f(900, 3));
		l.setPosition(0, i);
		l.setFillColor(sf::Color::White);

		sf::RectangleShape r(sf::Vector2f(3, 900));
		r.setPosition(i, 0);
		r.setFillColor(sf::Color::White);

		line.push_back(l);
		line.push_back(r);
	}

	for (auto p : pt) {
		int y = p.first;
		int x = p.second;
		sf::CircleShape c(10);
		c.setPosition(100 * x - 10, 100 * y - 10);
		c.setFillColor(sf::Color::Red);
		point.push_back(c);
	}
	for (auto tmp : path) {
		std::reverse(tmp.begin(), tmp.end());
		for (int i = 1; i < tmp.size(); ++i) {
			int sy = tmp[i - 1].first;
			int sx = tmp[i - 1].second;
			int ty = tmp[i].first;
			int tx = tmp[i].second;

			if (sx == tx) {
				sf::RectangleShape l(sf::Vector2f(4, 100));
				l.setPosition(100 * sx, 100 * std::min(sy, ty));
				l.setFillColor(sf::Color::Blue);
				route.push_back(l);
			}
			if (sy == ty) {
				sf::RectangleShape l(sf::Vector2f(100, 4));
				l.setPosition(100 * std::min(sx, tx), 100 * sy);
				l.setFillColor(sf::Color::Cyan);
				route.push_back(l);
			}
		}
	}

	int k = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::N)
					k++;
				if (event.key.code == sf::Keyboard::R)
					k = 0;
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (int i = 0; i < line.size(); ++i) {
			window.draw(line[i]);
		}
		for (int i = 0; i < route.size() && i < k; ++i) {
			window.draw(route[i]);
		}
		for (int i = 0; i < point.size(); ++i) {
			window.draw(point[i]);
		}
		window.display();
	}
}


std::vector<std::pair<int, int> > res;

void initDraw() {
	/*
	std::vector<std::vector<std::pair<int, int> > > path;
	ULL ans = 0;
	std::string infile = "./data/inputs_sat/input_" + std::to_string(1);
	infile += ".txt";
	std::string outfile = "./data/output_sat/output_" + std::to_string(1);
	outfile += ".txt";

	std::vector<std::pair<int, int> > pt;
	freopen(infile.c_str(), "r", stdin);
	int n, m, sx, sy, k;
	scanf("%d%d%d%d%d", &n, &m, &sx, &sy, &k);
	pt.push_back({ sx, sy });
	for (int i = 0; i < k; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		pt.push_back({ u, v });
	}

	getPath(infile.c_str(), outfile.c_str(), ans, path);
	draw(pt, path);
*/
}


void run() {
	for (int i = 0; i <= 64; ++i) {
		std::vector<std::vector<std::pair<int, int> > > path;
		ULL ans = 0;
		std::string infile = "./data/inputs_sat/input_" + std::to_string(i);
		infile += ".txt";
		std::string outfile = "./data/output_sat/output_" + std::to_string(i);
		outfile += ".txt";
		getPath(infile.c_str(), outfile.c_str(), ans, path);
	}
}

int main() {
	run();
}