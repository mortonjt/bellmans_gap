


#ifndef __REMOVE_FIRST_SET_ATTRIBUTES_HH__
#define __REMOVE_FIRST_SET_ATTRIBUTES_HH__


#include "../cfg/cfg.hh"


namespace Util {
	
	
	class RemoveFirstSetAttributes {
		
		public:
			
			RemoveFirstSetAttributes();
			~RemoveFirstSetAttributes();
			
			// Removes all attributes from the given grammar.
			void removeFromGrammar (CFG::CFG* grammar);
			
		private:
			
			void removeFromProduction (CFG::GrammarProduction* production);
			void removeFromBase (CFG::Base* b);
			
			
	};
	
	
}


#endif	// ifndef __REMOVE_FIRST_SET_ATTRIBUTES_HH__


