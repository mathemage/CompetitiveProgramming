class RectangularGrid {
public:
	long long countRectangles(int w, int h) {
		long long result = 0;
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				result += (i == j) ? 0 : i*j;
			}
		}
		return result;
	}
};
