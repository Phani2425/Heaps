class Solution {

  int union_find(int node, vector<int>& parents){
    if(node == parents[node]){
        return node;
    }

    return parents[node] = union_find(parents[node],parents);
  }

  void dsu(vector<int>& edge,vector<int>& parents, vector<int>& and_value){
     int x_parent = union_find(edge[0],parents);
     int y_parent = union_find(edge[1],parents);

     if(x_parent != y_parent){
        parents[y_parent] = x_parent;
        and_value[x_parent] = and_value[x_parent] & and_value[y_parent] & edge[2];
     }
     else{
        and_value[x_parent] &= edge[2];
     }
  }

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        //initialising the value we will be needing
        vector<int>parents(n);
        vector<int>and_value(n,-1);
        vector<int>results(query.size());
        //initially each node will be a disjoint set and each one will be parent of their own set
        for(int i=0;i<n;i++){
            parents[i] = i;
        }
        //ab bas jou edges wala array hai use traverse karo, usse data lo aur sets ko jodna shurur karo using dsu
        for(int i =0;i<edges.size();i++){
            dsu(edges[i],parents,and_value);
        }

        for(int i =0;i<query.size();i++){
            if(query[i][0]==query[i][1]){
                results[i]=0;
                continue;
            }
            int start_parent=union_find(query[i][0],parents);
            int end_parent= union_find(query[i][1],parents);
            if(start_parent != end_parent){
                results[i] = -1;
            }
            else{
                results[i] = and_value[start_parent];
            }
        }

        return results;
    }
};

// APPROACH:-

// acha jetebele mu question dekhili ki bhai smallest path hni ta bahara karibara achi so ete kn lamaba kariki deichi simpley mu 2 ta node bhitare samllest path barhaara karidebi bas but question tike alaga thila :-  sethire thila ki path value bw 2 nodes means the and operation betweena ll fo the edges present in that path

// ok so eta bi dekhiki bhabili ki hm hm ethire bi ta sammest length ra bahara kridele heijiba but case seta nathila .... so understand it like a story or a journey of optimising or finding out what can we use to solve the problems we are facing now

// so example re mu try kariki dekhili ki bhai jete paath lamba hauchi mane jeet adhika edges path re add hauchi thhe & operation of them never increases it either remain same(when weight of edges are same i.e when 2 edges have same weigt then the & operation will be same always) or it decreases...
// what a intresting observation ....

// MEANS AND OPERATION NEVER INCRESES THE VALUE THE RESULT EITHER REMAIN SAME OR DECREASE WHICH IS OBVIOUS BUT I NEVER NOTICED (BCS AND TA 1 SETEBEEL DABA NA JEBE BOTH BIT RE 1 THIBA)

// so is this means ki ame jete lamaba path create kariba bw 2 nodes we will have chance ti rreduce the path value that much??? yes....

// ok so jetebele amaku 2 ta nodes daba ame bas ta bhitare longest oath bahar kariki seta return karidaba longest path mane include all of the edges in the graph simple..but kn sabu bele ame bar bar count kariba se and operation ku??? na ame kn kariba na kouthi gote store karidaba se & operation ra value ku..but is this  enough???

// No ,bcs here the nodes can belong to diff sets or components or unions andd if this will be the case then they can be never connected and there wu=ill be no path bw them so ans will be 0...

// Acha so tahaele ame kemiti janiba ki semane gote uninon ru boli??
// Bhai UNION FIND AU KN PAIN ACHI???

// for description:- UNION FIND IS USED FOR FINDING THE PARENT OF A NODE
// AND THE DSU(DISJOINT SET UNION) USED FOR JOINING TWO SETS IF THEY ARE DISJOINTED ELSE IT NORMALLTY RETURNS AND THE DSU USES THE UNION FIND TO SEE IF THE 2 NODES ARE IN SAME SET OR NOT

// ok so here we will check ki if the 2 nodes i.e start and end belongs to same set or not first..but for that we must need to know there parents right??? so we will need to build the parents array and for that we must use the DSU...basically initially all elements are considered as of diff sets and then on the basis of relations given in the question we join them using DSU and update the parents vector

// after all done we just use that vector to see if 2 nodes belongs to the same union or not

// acha mane achi ame katah haucthile ki sabuthara & calculate kn kariba gote  jagare store karidaba...seta karibaku amaku ebe ahuri subidha haba...basically we will create a vector and as we are joiing diff nodes so ame gote set ra parent index re se set ra sabu edges ra & operated value store karidaba for direct access

//and ame se vector ku first -1 re intialise kariba as we want that jetebele bi kichi join haba bas ta parent index re thiba value ku ame new parent index re thiba value saha & kariki vector re store karidaba ay emitit hele ama pakhare updated value rahiba as we keep on joing unions for building actual graph   au sethipain jetebele first jooin haba for maintitng that value we initialie it with -1 as :- [any_num & -1 == any_num]


//AUR EK CHIZ YAAD RAKH KI AME DSU USE KARIKI GOTE STRUCTURE TIALRI KARUCHU BUT DONT THINK KI WE ARE CREATING THE GRAPH STRUCTURE ...NO WE ARE JUST CREATING A STRUCTURE WHICH SAYS WHAT WHAT NODES BELONGS TO WHICH SET OR UNION NOTHING ELSE

//AUR THINK THAT WHAY DO AND OPEARTION OF -1 WITH ANY NUMBER GIVES THAT NUMBER IN RETURN???

// OR OPERATION EITHER VALUE CONSTANT RAKHIBA OR INCRESE KARIBA AU AND OPEARTOOR VALUE CONSTANT RAKHIBA OR DECREASE KARIBA

//AND IF YOU NEED TO RESERVE THE 1 BITS FO EVERY NUMBER THEN USE OR OEPRATOR BETWEEN THEM AS BY THAT IF ANY NUMMBER WILL HAVE 1 AT NTH POSITION THE THE END RESULT WILL ANYHOW HAVE THE 1 AT NTH BIT
