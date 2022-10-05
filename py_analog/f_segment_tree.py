import pandas as pd
from matplotlib import collections  as mc
import matplotlib.pyplot as pl

def tree_df(Obj):
    dtTree = pd.DataFrame(Obj.l_plot())
    dtTree.columns = ['Level', 'Data', 'Left', 'Right']
    dtTree['nLvl'] = dtTree['Level'].astype(int) + 1
    return dtTree

def merge(l1, l2):
    ret = [[tuple(l1[i]),tuple(l2[i])] for i in range(0,len(l1))]
    return ret

def df_to_segments(df1, df2):
    df1 = df1.to_records(index=False)
    df1 = list(df1)
    df2 = df2.to_records(index=False)
    df2 = list(df2)
    ret = [[tuple(df1[i]),tuple(df2[i])] for i in range(0,len(df1))]
    ret = list(filter(lambda item: item[0][1] != item[1][1], ret))
    return ret

def plot_tree(lL, lR, df):
    lc = mc.LineCollection(lL, linewidths=0.5)
    rc = mc.LineCollection(lR, linewidths=0.5)
    fig, ax = pl.subplots()
    ax.add_collection(lc)
    ax.add_collection(rc)
    ax.scatter(x=df['Level'],y=df['Data'], color='red', s=2)
    ax.autoscale()
    ax.margins(0.1)
    return ax

def segmentated_tree(Obj, plot = False, ret = False):
    df = tree_df(Obj)
    lLeft = df_to_segments(df[['Level','Data']], df[['nLvl','Left']])
    lRight = df_to_segments(df[['Level','Data']], df[['nLvl','Right']])
    if (plot == True):
        plot_tree(lLeft, lRight, df)

    if (ret == True):
        return lLeft, lRight, df
