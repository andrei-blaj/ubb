namespace PPD_Lab4
{
    public static class Operation
    {
        public static T add<T>(T x, T y)
        {
            dynamic dx = x, dy = y;
            return dx + dy;
        }
        
        public static T mul<T>(T x, T y)
        {
            dynamic dx = x, dy = y;
            return dx * dy;
        }
    }
}