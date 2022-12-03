 if (floyed_weight[i][j] > (floyed_weight[i][k] + floyed_weight[k][j])
                        && (floyed_weight[k][j] != INF
                            && floyed_weight[i][k] != INF)) {
                    floyed_weight[i][j] = floyed_weight[i][k] + floyed_weight[k][j];
 }
