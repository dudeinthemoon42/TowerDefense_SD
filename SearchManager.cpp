#include "SearchManager.h"
#include "TowerManager.h"
#include "findpath.cpp"


int SearchManager::map[ MAP_WIDTH * MAP_HEIGHT ] = 
{
// 0001020304050607080910111213
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9, // 01
	9,9,9,9,9,9,9,9,9,9,9,9,9,9, // 02
	9,9,9,9,9,9,9,9,9,9,9,9,9,9, // 03
	9,9,9,9,9,9,9,9,9,9,9,9,9,9, // 04
	9,9,9,9,9,9,9,9,9,9,9,9,9,9, // 05
	1,1,1,1,1,1,1,1,1,1,1,1,1,1, // 06
	1,1,1,1,1,1,1,1,1,1,1,1,1,1, // 07
	1,1,1,1,1,1,1,1,1,1,1,1,1,1, // 08
	1,1,1,1,1,1,1,1,1,1,1,1,1,1  // 09
};

int SearchManager::lastRow = 0;
int SearchManager::lastCol = 0;

std::vector<int> SearchManager::lastRowVector;
std::vector<int> SearchManager::lastColVector;

void SearchManager::printMap(){
	int element;
	for(int y = 0; y < 10; y ++){
		for(int x = 0;x < 14; x ++){
			element = (y*14)+x;
			cout << SearchManager::map[element] << ",";
		} 
			cout << endl;
	}
}

void SearchManager::updateMap(){
	int element;
	for(unsigned int x = 0; x < TowerManager::tileAr.size(); x ++){
	
		element = (TowerManager::tileAr.at(x)->col*14)+TowerManager::tileAr.at(x)->row;
		//cout << SearchManager::map[(TowerManager::tileAr.at(x)->col*14)+TowerManager::tileAr.at(x)->row] << endl;
		if(TowerManager::tileAr.at(x)->taken){
			SearchManager::map[element] = 9;
		}
		else
			SearchManager::map[element] = 1;
	}
	
}

bool SearchManager::runMap (int startRow, int startCol){

	AStarSearch<MapSearchNode> astarsearch;

	unsigned int SearchCount = 0;

	const unsigned int NumSearches = 1;

	while(SearchCount < NumSearches)
	{

		// Create a start state
		MapSearchNode nodeStart;
		nodeStart.x = startRow;
		nodeStart.y = startCol; 

		// Define the goal state
		MapSearchNode nodeEnd;
		nodeEnd.x = MAP_WIDTH-1;						
		nodeEnd.y = MAP_HEIGHT-1; 
		
		// Set Start and goal states
		
		astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );

		unsigned int SearchState;
		unsigned int SearchSteps = 0;

		do
		{
			SearchState = astarsearch.SearchStep();

			SearchSteps++;

	#if DEBUG_LISTS


			int len = 0;

			MapSearchNode *p = astarsearch.GetOpenListStart();
			while( p )
			{
				len++;
	#if !DEBUG_LIST_LENGTHS_ONLY			
				((MapSearchNode *)p)->PrintNodeInfo();
	#endif
				p = astarsearch.GetOpenListNext();
				
			}

			cout << "Open list has " << len << " nodes\n";

			len = 0;

			cout << "Closed:\n";
			p = astarsearch.GetClosedListStart();
			while( p )
			{
				len++;
	#if !DEBUG_LIST_LENGTHS_ONLY			
				p->PrintNodeInfo();
	#endif			
				p = astarsearch.GetClosedListNext();
			}

			cout << "Closed list has " << len << " nodes\n";
	#endif

		}
		while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );

		if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED )
		{
			//cout << "Search found goal state\n";

				MapSearchNode *node = astarsearch.GetSolutionStart();

	#if DISPLAY_SOLUTION
				cout << "Displaying solution\n";
	#endif
				int steps = 0;

				//node->PrintNodeInfo();
				SearchManager::lastRowVector.clear();
				SearchManager::lastColVector.clear();

				SearchManager::lastRowVector.push_back(node->x);
				SearchManager::lastColVector.push_back(node->y);
				for( ;; )
				{
					node = astarsearch.GetSolutionNext();

					if( !node )
					{
						break;
					}

					SearchManager::lastRowVector.push_back(node->x);
					SearchManager::lastColVector.push_back(node->y);

					//node->PrintNodeInfo();
					if(steps == 0){
						SearchManager::lastRow = node->x;
						SearchManager::lastCol = node->y;
						//node->PrintNodeInfo();
						//cout << "(" << lastRow << "," << lastCol << ")" << endl;
					}
					steps ++;
				};

				//cout << "Solution steps " << steps << endl;

				// Once you're done with the solution you can free the nodes up
				astarsearch.FreeSolutionNodes();

				return true;
		}
		else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED ) 
		{
			cout << "Search terminated. Did not find goal state\n";
			return false;
		}

		SearchCount ++;

		astarsearch.EnsureMemoryFreed();
	}

}

