#ifnded _WD_H_
#define _WD_H_

class WD: public Potion {
public:
	WD();
	~WD();

	void getPickedBy(Player &p);
};

#endif