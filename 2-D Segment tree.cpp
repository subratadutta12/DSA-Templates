int t[(4 * n) + 5][(4 * m) + 5];

/*here vx and vy are the row number and coloumn number of the segment tree
lx and ly are the row number and coloumn number of the segment tree
lx and rx denotes the top and bottom row of a range
ly and ry represent the left and right coloumn of a range*/

// To build a segment tree just call build_x(1, 0, n-1,m-1) where n and m are the number of rows and coloumns respectively. The original matrix a is in 0-based indexing

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = t[vx * 2][vy] + t[vx * 2 + 1][vy];
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy * 2, ly, my);
        build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry);
        t[vx][vy] = t[vx][vy * 2] + t[vx][vy * 2 + 1];
    }
}

void build_x(int vx, int lx, int rx, int m) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx * 2, lx, mx, m);
        build_x(vx * 2 + 1, mx + 1, rx, m);
    }
    build_y(vx, lx, rx, 1, 0, m);
}


// For query a sub-matrix just call query_x(1,0,n-1,r1,r2,c1,c2,m-1) where n and m are the number of rows and coloumns respectively (r1,c1) is the row and coloumn of top-left cell and (r2,c2) is the row and coloumn of bottom-right cell. Note: (r1,c1,r2,c2) are in 0-based indexing.

int query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry)
        return 0;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return query_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy))
           + query_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry);
}

int query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry, int m) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return query_y(vx, 1, 0, m, ly, ry);
    int tmx = (tlx + trx) / 2;
    return query_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry, m)
           + query_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry, m);
}


// For point update just call update_x(1,0,n-1,r,c,new_value,m-1) where n and m are the number of rows and coloumns respectively and (r,c) is the cell to be updated new_value is the value to which to be stored. Note: (r,c) are in 0-based indexing.

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = new_val;
        else
            t[vx][vy] = t[vx * 2][vy] + t[vx * 2 + 1][vy];
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
        t[vx][vy] = t[vx][vy * 2] + t[vx][vy * 2 + 1];
    }
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val, int m) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx * 2, lx, mx, x, y, new_val, m);
        else
            update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val, m);
    }
    update_y(vx, lx, rx, 1, 0, m, x, y, new_val);
}
