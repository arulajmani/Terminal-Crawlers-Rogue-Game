#include "human.h"
using namespace std;

const int defaultHP = 140;
const int defaultAtk = 20;
const int defaultDef = 20;

Human::Human(): Player{"Human", defaultHP, defaultDef, defaultAtk} {}
Human::~Human() {}

