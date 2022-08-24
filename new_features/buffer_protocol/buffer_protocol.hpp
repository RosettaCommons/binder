
#pragma once

namespace buffer_protocol_example {

	class Matrix {
	public:
		Matrix(int rows, int cols) : m_rows(rows), m_cols(cols) {
			m_data = new float[rows*cols];
			for(int i =0; i<rows*cols; i++) m_data[i] = 0;
		}
		float get(int i, int j) { return m_data[i*m_cols+j];}
		float *data() { return m_data; }
		int rows() const { return m_rows; }
		int cols() const { return m_cols; }
	private:
		int m_rows, m_cols;
		float *m_data;
	};

}


