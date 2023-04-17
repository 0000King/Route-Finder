//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void cityCheck(String s, int *si)
{
	if(s == "Sector 1")
		*si = 0;
	else if(s == "Sector 2")
		*si = 1;
	else if(s == "Sector 3")
		*si = 2;
	else if(s == "Sector 4")
		*si = 3;
	else if(s == "Sector 5")
		*si = 4;
	else if(s == "Sector 6")
		*si = 5;
	else if(s == "Sector 7")
		*si = 6;
	else if(s == "Sector 8")
		*si = 7;
	else if(s == "Sector 9")
		*si = 8;
}

int *dijkstra(int route[], int distance[], int startnode, int endnode)
{
	int n = 9;
	int G[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
					{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
					{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
					{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
					{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
					{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
					{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
					{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
					{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	int cost[9][9], pred[9];
	int visited[9], count, mindistance, nextnode, i,j;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0)
				cost[i][j]=9999;
			else
				cost[i][j]=G[i][j];

	for(i=0;i< n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count < n-1){
		mindistance=9999;
		for(i=0;i < n;i++)
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			count++;
	}
	if(endnode!=startnode)
	{
		int k = 1;
		route[k] = endnode;
		j=endnode;
		do
		{
			j=pred[j];
			route[++k] = j;
		}
		while(j!=startnode);
		route[0] = k;
	}
	return route;
}

void __fastcall TForm1::Find_RouteClick(TObject *Sender)
{
	String s1 = SourceInput -> Text;
	String s2 = DestinationInput -> Text;
	int si1, si2;
	cityCheck(s1, &si1);
	cityCheck(s2, &si2);
	int route[10], distance[9];
	int *rou = dijkstra(route, distance, si1, si2);
	String str = "Minimum Distance = ";
	str += distance[*(route+1)];
    str += "\n";
	int i = *rou;
	if(*(rou+i) == 0)
		str += "Sector 1";
	else if(*(rou+i) == 1)
		str += "Sector 2";
	else if(*(rou+i) == 2)
		str += "Sector 3";
	else if(*(rou+i) == 3)
		str += "Sector 4";
	else if(*(rou+i) == 4)
		str += "Sector 5";
	else if(*(rou+i) == 5)
		str += "Sector 6";
	else if(*(rou+i) == 6)
		str += "Sector 7";
	else if(*(rou+i) == 7)
		str += "Sector 8";
	else if(*(rou+i) == 8)
		str += "Sector 9";
	i -= 1;
	for(; i >= 1; i--	)
	{
		str += " -> ";
		if(*(rou+i) == 0)
			str += "Sector 1";
		else if(*(rou+i) == 1)
			str += "Sector 2";
		else if(*(rou+i) == 2)
			str += "Sector 3";
		else if(*(rou+i) == 3)
			str += "Sector 4";
		else if(*(rou+i) == 4)
			str += "Sector 5";
		else if(*(rou+i) == 5)
			str += "Sector 6";
		else if(*(rou+i) == 6)
			str += "Sector 7";
		else if(*(rou+i) == 7)
			str += "Sector 8";
		else if(*(rou+i) == 8)
			str += "Sector 9";
	}
	Route -> Text = str;
}
//---------------------------------------------------------------------------
