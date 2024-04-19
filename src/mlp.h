#ifndef LS_MLP_H
#define LS_MLP_H

#include "matrix.h"
#include "activations.h"

#include <memory>

struct Layer {
	uint neurons;
	float(&activation)(float);
	float(&activationP)(float);

	Layer(uint _neurons, float(&_activation)(float), float(&_activationP)(float)) : neurons(_neurons), activation(_activation), activationP(_activationP) {}
};

class MLP {

private:
	std::vector<Layer> m_layers;

	std::unique_ptr<Mat<float>> inputs;
	std::vector<std::unique_ptr<Mat<float>>> m_n;	/* pre-activation */
	std::vector<std::unique_ptr<Mat<float>>> m_w;	/* weights */
	std::vector<std::unique_ptr<Mat<float>>> m_b;	/* biases */
	std::vector<std::unique_ptr<Mat<float>>> m_a;	/* activations */

public:
	MLP(std::vector<Layer> layers) : m_layers(layers) {

		inputs.reset(new Mat<float>(layers[0].neurons, 1));

		/*
		for (int i = 1; i < layers.size(); ++i) {
			m_n.push_back(std::unique_ptr<Mat<float>>(new Zeros<float>(layers[i].neurons, 1)));
			m_w.push_back(std::unique_ptr<Mat<float>>(new Random<float>(layers[i].neurons, layers[i-1].neurons)));
			m_b.push_back(std::unique_ptr<Mat<float>>(new Ones<float>(layers[i].neurons, 1)));
			m_a.push_back(std::unique_ptr<Mat<float>>(new Zeros<float>(layers[i].neurons, 1)));
		}
		*/
	}

};

#endif /* LS_MLP_H */
