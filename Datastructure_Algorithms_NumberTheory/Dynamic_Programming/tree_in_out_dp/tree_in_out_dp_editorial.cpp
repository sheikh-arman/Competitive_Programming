void dfs1(int u, int par)
{
    in[u] = 0;
    int v;
    for(int i = 0; i < adj[u].size(); i++)
    {
        v = adj[u][i];
        if (v == par)
            continue;

        dfs1(v, u);

        in[u] = max(in[u], 1 + in[v]);
    }
}
void dfs2(int u, int par)
{
    int mx1, mx2;

    mx1 = mx2 = -1;

    int v;
    for(int i = 0; i < adj[u].size(); i++)
    {
        v = adj[u][i];
        if(v == par)
            continue;
        if(in[v] >= mx1)
            mx2 = mx1, mx1 = in[v];
        else if(in[v] > mx2)
            mx2 = in[v];
    }

    for(int i = 0; i < adj[u].size(); i++)
    {
        v = adj[u][i];
        if (v == par)
            continue;

        int use = mx1;
        if(mx1 == in[v])
            use = mx2;

        out[v] = max(1+out[u], 2+use);

        dfs2(v, u);
    }
}
