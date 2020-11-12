make testing:
	g++ -std=c++11 Player.cpp testing-playerclassmain.cpp -o TestingPlayerClassDriver
	g++ -std=c++11 choc_top.cpp Player.cpp testing-choc_topclassmain.cpp -o TestingChocTopClassDriver
	g++ -std=c++11 chocolateFrog.cpp Player.cpp testing-chocolatefrogclassmain.cpp -o TestingChocolateFrogClassDriver
	g++ -std=c++11 popcorn.cpp Player.cpp testing-popcornclassmain.cpp -o TestingPopcornClassDriver
	g++ -std=c++11 Cola.cpp Player.cpp testing-colaclassmain.cpp -o TestingColaClassDriver
	g++ -std=c++11 Slushie.cpp Player.cpp testing-slushieclassmain.cpp -o TestingSlushieClassDriver
	g++ -std=c++11 Water.cpp Player.cpp testing-waterclassmain.cpp -o TestingWaterClassDriver
	g++ -std=c++11 Player.cpp testing-movieplayerintergration.cpp -o TestingMovieIntegrationClassDriver

make runtesting:
	./TestingPlayerClassDriver
	./TestingChocTopClassDriver
	./TestingChocolateFrogClassDriver
	./TestingPopcornClassDriver
	./TestingColaClassDriver
	./TestingSlushieClassDriver
	./TestingWaterClassDriver
	./TestingMovieIntegrationClassDriver

make main:
	g++ -std=c++11 Player.cpp choc_top.cpp chocolateFrog.cpp popcorn.cpp Cola.cpp Slushie.cpp Water.cpp Movie_main.cpp -o MainDriver

make runmain:
	./MainDriver

