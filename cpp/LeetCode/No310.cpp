/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. 
In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges 
where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree
, you can choose any node of the tree as the root. 
When you select a node x as the root, the result tree has height h. 
Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/
#include <iostream>
#include <vector>
#include "Debug\VectorDebug.h"
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int minHeight = INT_MAX;
        vector<int> in(n);
        for(vector<int>& edge : edges){
            in[edge[0]]++;
            in[edge[1]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> heap;
        for(int i=0;i<n;i++) heap.push({in[i], i});
        vector<int> res;
        while(!heap.empty()){
            int node = heap.top().second;
            heap.pop();
            int ret = getMHT(n, edges, node, minHeight);
            
            if(ret<minHeight){
                minHeight = ret;
                res = {node};
            }
            else if(ret==minHeight){
                res.push_back(node);
            }
        }
        return res;
    }
private:
    int getMHT(int n, vector<vector<int>>& edges, int src, int last){
        vector<bool> seen(n, false);
        vector<vector<int>> ajList(n);
        for(vector<int>& edge : edges){
            ajList[edge[0]].push_back(edge[1]);
            ajList[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(src);
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            res++;
            if(res>last) return res;
            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();
                seen[node] = true;
                for(int neighbor : ajList[node]){
                    if(!seen[neighbor]){
                        q.push(neighbor);
                    }
                }
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    int n;
    vector<vector<int>> edges;
    vector<int> res;

    n = 4;
    edges = {{1,0},{1,2},{1,3}};
    res = solution.findMinHeightTrees(n, edges);
    printVector(res);

    n = 6;
    edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    res = solution.findMinHeightTrees(n, edges);
    printVector(res);

    n = 909;
    edges = {{0,1},{0,2},{2,3},{0,4},{4,5},{0,6},{6,7},{0,8},{7,9},{1,10},{0,11},{10,12},{8,13},{3,14},{1,15},{1,16},{4,17},{7,18},{15,19},{1,20},{14,21},{9,22},{14,23},{15,24},{7,25},{0,26},{24,27},{13,28},{22,29},{18,30},{18,31},{17,32},{14,33},{20,34},{1,35},{14,36},{14,37},{30,38},{13,39},{6,40},{32,41},{17,42},{23,43},{23,44},{6,45},{27,46},{9,47},{4,48},{16,49},{31,50},{21,51},{21,52},{31,53},{53,54},{18,55},{3,56},{7,57},{52,58},{14,59},{10,60},{20,61},{17,62},{2,63},{36,64},{25,65},{53,66},{61,67},{23,68},{14,69},{29,70},{63,71},{12,72},{6,73},{11,74},{73,75},{60,76},{38,77},{61,78},{71,79},{20,80},{24,81},{60,82},{52,83},{68,84},{22,85},{36,86},{85,87},{9,88},{15,89},{56,90},{16,91},{67,92},{24,93},{63,94},{41,95},{57,96},{83,97},{90,98},{38,99},{54,100},{97,101},{4,102},{51,103},{31,104},{22,105},{102,106},{95,107},{71,108},{9,109},{53,110},{62,111},{110,112},{5,113},{27,114},{104,115},{35,116},{14,117},{0,118},{106,119},{37,120},{8,121},{26,122},{87,123},{49,124},{74,125},{61,126},{17,127},{89,128},{58,129},{33,130},{36,131},{50,132},{43,133},{121,134},{32,135},{113,136},{64,137},{73,138},{13,139},{133,140},{89,141},{36,142},{86,143},{117,144},{11,145},{70,146},{98,147},{82,148},{28,149},{61,150},{66,151},{59,152},{51,153},{49,154},{61,155},{76,156},{155,157},{57,158},{112,159},{19,160},{60,161},{88,162},{62,163},{52,164},{126,165},{48,166},{47,167},{136,168},{15,169},{7,170},{85,171},{61,172},{110,173},{81,174},{135,175},{60,176},{95,177},{171,178},{161,179},{44,180},{19,181},{175,182},{107,183},{23,184},{66,185},{122,186},{128,187},{147,188},{139,189},{135,190},{19,191},{103,192},{51,193},{158,194},{99,195},{75,196},{4,197},{26,198},{131,199},{167,200},{83,201},{131,202},{55,203},{32,204},{164,205},{98,206},{86,207},{170,208},{170,209},{188,210},{40,211},{46,212},{31,213},{18,214},{116,215},{13,216},{212,217},{148,218},{88,219},{19,220},{81,221},{137,222},{23,223},{58,224},{163,225},{145,226},{116,227},{45,228},{31,229},{47,230},{66,231},{82,232},{59,233},{229,234},{164,235},{122,236},{31,237},{143,238},{178,239},{32,240},{97,241},{89,242},{117,243},{191,244},{76,245},{25,246},{217,247},{106,248},{37,249},{12,250},{47,251},{163,252},{247,253},{253,254},{19,255},{245,256},{67,257},{108,258},{50,259},{115,260},{67,261},{248,262},{148,263},{149,264},{220,265},{54,266},{134,267},{2,268},{161,269},{265,270},{31,271},{83,272},{162,273},{267,274},{21,275},{72,276},{26,277},{112,278},{268,279},{41,280},{84,281},{196,282},{281,283},{109,284},{118,285},{66,286},{167,287},{142,288},{154,289},{262,290},{158,291},{216,292},{26,293},{30,294},{60,295},{276,296},{72,297},{215,298},{7,299},{69,300},{289,301},{54,302},{210,303},{280,304},{204,305},{186,306},{217,307},{305,308},{225,309},{13,310},{3,311},{110,312},{82,313},{155,314},{22,315},{66,316},{223,317},{252,318},{229,319},{247,320},{231,321},{190,322},{308,323},{26,324},{245,325},{123,326},{91,327},{308,328},{17,329},{78,330},{136,331},{7,332},{146,333},{318,334},{273,335},{161,336},{35,337},{241,338},{282,339},{133,340},{136,341},{8,342},{146,343},{117,344},{15,345},{102,346},{52,347},{21,348},{166,349},{131,350},{178,351},{142,352},{7,353},{255,354},{346,355},{162,356},{16,357},{253,358},{285,359},{23,360},{7,361},{96,362},{128,363},{231,364},{223,365},{275,366},{347,367},{244,368},{203,369},{55,370},{182,371},{170,372},{270,373},{315,374},{85,375},{346,376},{212,377},{102,378},{319,379},{252,380},{264,381},{351,382},{164,383},{233,384},{361,385},{175,386},{230,387},{331,388},{57,389},{119,390},{118,391},{251,392},{306,393},{255,394},{199,395},{238,396},{17,397},{197,398},{151,399},{356,400},{395,401},{191,402},{16,403},{13,404},{110,405},{313,406},{340,407},{161,408},{301,409},{44,410},{364,411},{272,412},{100,413},{312,414},{307,415},{347,416},{374,417},{187,418},{328,419},{118,420},{311,421},{321,422},{108,423},{395,424},{190,425},{299,426},{79,427},{68,428},{240,429},{386,430},{371,431},{5,432},{255,433},{320,434},{376,435},{81,436},{68,437},{54,438},{421,439},{423,440},{311,441},{41,442},{3,443},{400,444},{137,445},{253,446},{335,447},{376,448},{1,449},{212,450},{169,451},{383,452},{401,453},{383,454},{54,455},{59,456},{35,457},{121,458},{173,459},{388,460},{456,461},{81,462},{368,463},{219,464},{178,465},{114,466},{384,467},{104,468},{268,469},{170,470},{246,471},{319,472},{258,473},{326,474},{241,475},{25,476},{468,477},{444,478},{418,479},{405,480},{261,481},{447,482},{140,483},{30,484},{375,485},{75,486},{455,487},{64,488},{236,489},{454,490},{207,491},{431,492},{290,493},{84,494},{409,495},{315,496},{343,497},{480,498},{451,499},{155,500},{262,501},{111,502},{441,503},{237,504},{387,505},{275,506},{75,507},{259,508},{465,509},{433,510},{217,511},{450,512},{30,513},{479,514},{179,515},{102,516},{181,517},{153,518},{208,519},{380,520},{256,521},{276,522},{253,523},{417,524},{179,525},{305,526},{450,527},{407,528},{442,529},{99,530},{381,531},{89,532},{507,533},{347,534},{132,535},{445,536},{197,537},{255,538},{479,539},{322,540},{277,541},{342,542},{44,543},{443,544},{322,545},{96,546},{397,547},{195,548},{316,549},{13,550},{397,551},{405,552},{250,553},{365,554},{108,555},{213,556},{97,557},{406,558},{156,559},{421,560},{80,561},{328,562},{303,563},{243,564},{269,565},{485,566},{457,567},{371,568},{201,569},{337,570},{183,571},{221,572},{113,573},{447,574},{244,575},{429,576},{126,577},{69,578},{535,579},{303,580},{283,581},{567,582},{209,583},{21,584},{227,585},{21,586},{16,587},{268,588},{45,589},{107,590},{141,591},{40,592},{157,593},{328,594},{68,595},{225,596},{219,597},{301,598},{44,599},{515,600},{334,601},{229,602},{95,603},{177,604},{408,605},{119,606},{200,607},{334,608},{142,609},{437,610},{391,611},{272,612},{231,613},{566,614},{64,615},{186,616},{584,617},{9,618},{369,619},{21,620},{477,621},{17,622},{604,623},{228,624},{225,625},{615,626},{403,627},{90,628},{459,629},{171,630},{52,631},{626,632},{385,633},{96,634},{120,635},{161,636},{86,637},{14,638},{302,639},{402,640},{191,641},{355,642},{475,643},{267,644},{616,645},{10,646},{595,647},{295,648},{332,649},{78,650},{334,651},{402,652},{215,653},{328,654},{383,655},{461,656},{608,657},{590,658},{427,659},{115,660},{301,661},{579,662},{361,663},{602,664},{215,665},{181,666},{292,667},{126,668},{160,669},{640,670},{559,671},{301,672},{221,673},{226,674},{430,675},{403,676},{484,677},{395,678},{659,679},{169,680},{627,681},{48,682},{421,683},{589,684},{100,685},{662,686},{244,687},{440,688},{623,689},{626,690},{46,691},{148,692},{688,693},{87,694},{635,695},{609,696},{186,697},{317,698},{654,699},{412,700},{291,701},{481,702},{639,703},{596,704},{40,705},{382,706},{222,707},{445,708},{409,709},{612,710},{214,711},{658,712},{363,713},{399,714},{335,715},{274,716},{21,717},{109,718},{232,719},{551,720},{113,721},{78,722},{20,723},{172,724},{192,725},{291,726},{47,727},{378,728},{372,729},{349,730},{696,731},{362,732},{509,733},{603,734},{481,735},{633,736},{709,737},{610,738},{671,739},{525,740},{176,741},{329,742},{451,743},{23,744},{190,745},{473,746},{234,747},{470,748},{160,749},{599,750},{50,751},{176,752},{69,753},{525,754},{97,755},{692,756},{117,757},{364,758},{627,759},{393,760},{415,761},{222,762},{737,763},{461,764},{392,765},{28,766},{663,767},{274,768},{673,769},{607,770},{160,771},{222,772},{605,773},{342,774},{418,775},{269,776},{371,777},{235,778},{299,779},{725,780},{297,781},{233,782},{260,783},{214,784},{247,785},{170,786},{517,787},{612,788},{246,789},{52,790},{173,791},{490,792},{297,793},{451,794},{309,795},{65,796},{352,797},{178,798},{403,799},{338,800},{342,801},{282,802},{317,803},{361,804},{479,805},{141,806},{280,807},{303,808},{265,809},{172,810},{42,811},{39,812},{133,813},{339,814},{744,815},{765,816},{165,817},{323,818},{238,819},{95,820},{76,821},{37,822},{283,823},{410,824},{464,825},{666,826},{23,827},{669,828},{77,829},{512,830},{739,831},{813,832},{342,833},{18,834},{354,835},{641,836},{318,837},{480,838},{287,839},{521,840},{29,841},{224,842},{9,843},{119,844},{47,845},{291,846},{239,847},{249,848},{448,849},{347,850},{380,851},{354,852},{473,853},{55,854},{413,855},{635,856},{350,857},{454,858},{80,859},{550,860},{361,861},{660,862},{427,863},{535,864},{317,865},{162,866},{427,867},{732,868},{4,869},{611,870},{771,871},{311,872},{600,873},{809,874},{634,875},{618,876},{123,877},{373,878},{600,879},{686,880},{610,881},{361,882},{108,883},{397,884},{766,885},{440,886},{434,887},{627,888},{263,889},{316,890},{651,891},{668,892},{119,893},{696,894},{624,895},{133,896},{228,897},{71,898},{162,899},{496,900},{749,901},{802,902},{471,903},{117,904},{84,905},{212,906},{42,907},{351,908}};
    res = solution.findMinHeightTrees(n, edges);
    printVector(res);
    return 0;
}