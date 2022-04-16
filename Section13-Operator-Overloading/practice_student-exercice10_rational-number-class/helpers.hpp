int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    int ans = a;
    ans = (((b * ans)) / (gcd(b, ans)));

    return ans;
}