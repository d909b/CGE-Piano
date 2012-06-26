/*
 * MyMaterial.h
 *
 *  Created on: Jun 26, 2012
 *      Author: steindl
 */

#ifndef MYMATERIAL_H_
#define MYMATERIAL_H_

class MyMaterial
{
public:
	MyMaterial();
	~MyMaterial();

	float getShininess() const {
		return shininess;
	}

	void setShininess(float shininess) {
		this->shininess = shininess;
	}

	int getTexCount() const {
		return texCount;
	}

	void setTexCount(int texCount) {
		this->texCount = texCount;
	}
	float ambient[4];
	float specular[4];
	float emissive[4];
	float diffuse[4];
private:
	float shininess;
	int texCount;
};


#endif /* MYMATERIAL_H_ */
