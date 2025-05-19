import matplotlib.pyplot as plt
import numpy as np

N = 10000
B = np.linspace(0.1, 2, N)
E = np.empty(N)
M = np.empty(N)
Xi = np.empty(N)

for i in range(N):
	E[i] = B[i] * (2 * int(1/B[i]) + 1 - int(1/B[i]) * (int(1/B[i]) + 1) * B[i])
	M[i] = (2 * int(1/B[i]) + 1 - 2 * int(1/B[i]) * (int(1/B[i]) + 1) * B[i])
	Xi[i] = (- 2 * int(1/B[i]) * (int(1/B[i]) + 1))

plt.plot(B, E)
plt.show()

plt.plot(B, M)
plt.show()

plt.plot(B, Xi)
plt.show()

