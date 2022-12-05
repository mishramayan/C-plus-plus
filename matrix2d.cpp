#include "matrix2d.h";

void matrix2d::init(int a, int b, int c) {
	row_ = a;
	col_ = b;
	val_ = c;
	m_ = new int* [row_];
	for (int i = 0; i < row_; i++) {
		m_[i] = new int[col_];
	}

	set_(val_);
}

void matrix2d::set_(int v) {
	for (int i = 0; i < row_; i++) {
		for (int j = 0; j < col_; j++) {
			m_[i][j] = val_;
		}
	}
}

void matrix2d::init(const char* s)
{
    row_ = 0;
    col_ = 0;
    m_ = 0;

    int k = 0;
    int n = 0;
    int i = 0;
    int j = 0;
    int numcol = 0;
    int numrow = 0;
    int idx = 0;
    bool failed = false;
    int temp[1024];
    char ch = 'a';
    do {
        ch = s[i++];
        if ((ch == ' ') && (j == 0)) {

        }
        else if (ch == '\0' || ch == '|' || ch == ' ') {
            if (j) {
                ++k;
                temp[idx++] = n;
                j = 0;
            }
            n = 0;
            if (ch == '\0' || ch == '|') {
                ++numrow;
                if (numcol) {
                    if (numcol != k) {
                        failed = true;
                        break;
                    }
                }
                else {
                    numcol = k;
                }
                k = 0;
            }
        }
        else if (ch >= '0' && ch <= '9') {
            n = 10 * n + (ch - '0');
            ++j;
        }
        else {
            failed = true;
            break;
        }
    } while (ch != '\0');

    if (!failed && numrow && numcol) {
        assert(idx == numrow * numcol);
        row_ = numrow;
        col_ = numcol;
        m_ = new int* [row_];
        for (int k = 0; k < row_; ++k) {
            m_[k] = new int[col_];
        }
        int i = 0;
        for (int r = 0; r < row_; ++r) {
            for (int c = 0; c < col_; ++c) {
                m_[r][c] = temp[i++];
            }
        }
        assert(i == idx);
    }
}

void matrix2d::print(const char* t) const
{
	cout << t << endl;
	if (isEmpty()) {
		cout << "----------Empty Matrix----------" << endl;
	}
	else {
		for (int i = 0; i < row_; i++) {
			for (int j = 0; j < col_; j++) {
				cout << m_[i][j] << " ";
			}
			cout << endl;
		}
	}
    cout << endl;
}

void matrix2d::fini()
{
    if (!isEmpty()) {
        for (int i = 0; i < row_; i++) {
            delete m_[i];
        }
        delete[] m_;
    }

    row_ = 0;
    col_ = 0;
    m_ = 0;
}

matrix2d matrix2d::add(matrix2d a)
{
    matrix2d s;
    s.init();
    const matrix2d& b = *(this);
    if (b.row_ == a.row_ && b.col_ == a.col_) {
        s.init(a.row_, a.col_);
        for (int i = 0; i < row_; i++) {
            for (int j = 0; j < col_; j++) {
                s.m_[i][j] = b.m_[i][j] +  a.m_[i][j];
            }
        }
    }
	return s;
}

matrix2d matrix2d::mult(matrix2d a)
{
    matrix2d s;
    s.init();
    matrix2d& t = *(this);
    if (!t.isEmpty() && !a.isEmpty()) {
        if (col_ == a.row_) {
            s.init(row_, a.col_);
            for (int i = 0; i < t.row_; i++) {
                for (int j = 0; j < a.col_; j++) {
                    s.m_[i][j] = 0;
                    for (int k = 0; k < t.col_; k++) {
                        s.m_[i][j] = s.m_[i][j] + (t.m_[i][k] * a.m_[k][j]);
                    }
                }
            }
        }
    }
    
	return s;
}

bool matrix2d::isEqual(const matrix2d& a) const
{
    if (row_ == a.row_ && col_ == a.col_) {
        for (int i = 0; i < row_; ++i) {
            for (int j = 0; j < col_; ++j) {
                if (m_[i][j] != a.m_[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
	return false;
}

bool matrix2d::isEmpty() const
{
	if (row_ == 0 || col_ == 0) {
		return true;
	}
	return false;
}
