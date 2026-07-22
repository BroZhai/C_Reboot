int get_random(int min, int max); // 取得指定范围内的随机值 [min, max];
// 潜在bug: 由于拿的是'系统秒数时间戳'当的种子, 调用太快时会发生'重复随机值'的问题