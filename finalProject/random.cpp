#include "random.h"
float getProb(float min, float max) {
	std::random_device rd;
	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
	std::mt19937 mt{ ss };
	std::uniform_real_distribution<float> _dist{ min,max };
	return _dist(mt);
}
