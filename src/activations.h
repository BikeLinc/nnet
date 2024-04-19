#ifndef LS_ACTIVATIONS_H
#define LS_ACTIVATIONS_H

#include <cmath>

namespace activations {

	float identity(float x) {
		return x;
	}

	float identityP(float x) {
		return 1;
	}
	
	float unitStep(float x) {
		if (x < 0) {
			return 0;
		}
		else {
			return 1;
		}
	}

	float unitStepP(float x) {
		return 0;
	}

	float sigmoid(float x) {
		return 1 / (1 + exp(-x));
	}

	float sigmoidP(float x) {
		return sigmoid(x) * (1 - sigmoid(x));
	}

	float tanh(float x) {
		return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
	}

	float tanhP(float x) {
		return 1 - powf(tanh(x), 2);
	}

};

#endif /* LS_ACTIVATIONS_H */
