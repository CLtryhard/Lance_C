//
// Created by Lance on 2021/9/24.
//
#define MaxSize 255

/* 3.3.7 二.3 */
double PnX(int n, double x) {
    struct stack{
        int no;
        double val;
    }st[MaxSize];
    int top = -1, i;
    double fv1 = 1, fv2 = 2 * x;
    for (i = n; i >= 2; i--)
    {
        top++;
        st[top].no = i;
    }
    while (top>=0)
    {
        st[top].val = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].val;
        top--;
    }
    if (n==0)
    {
        return fv1;
    }
    return fv2;
}

int main() {
    PnX(4, 5);
}