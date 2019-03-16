#include <bits/stdc++.h>
#include "calcBFS.h"
#include "util.h"
typedef unsigned long long ULL;

constexpr auto WIDTH = 900;
constexpr auto HEIGHT = 900;

/*
void draw() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;
	sf::Font font;
	font.loadFromFile("./fonts/arial.ttf");

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Hackathon_Viz", sf::Style::Default, settings);;

	std::vector<sf::RectangleShape> line;

	sf::RectangleShape l(sf::Vector2f(200, 4));
	l.setPosition(450, 450);
	l.setFillColor(sf::Color::White);

	line.push_back(l);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		for (auto l : line) {
			window.draw(l);
		}
		window.display();

	}

}
*/

int main() {
	for (int i = 0; i <= 64; ++i) {
		std::vector<std::vector<std::pair<int, int> > > path;
		ULL ans = 0;
		std::string infile = "./data/inputs_sat/input_" + std::to_string(i);
		infile += ".txt";
		std::string outfile = "./data/output_sat/output_" + std::to_string(i);
		outfile += ".txt";
		getPath(infile.c_str(), outfile.c_str(), ans, path);

		printf("%llu\n", ans);
		for (auto tmp : path) {
			std::reverse(tmp.begin(), tmp.end());
			for (auto p : tmp) {
				printf("%d %d\n", p.first, p.second);
			}
		}
	}
}