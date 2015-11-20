#ifndef PoolFactory_h
#define PoolFactory_h

#include <vector>

using namespace std;

namespace PF
{
    template <class T>
    class PoolFactory
    {
        public:

        PoolFactory()
        {
            miNext = -1;
            miNumberAllocated = 0;
            miReUseIndex = -1;
            miReUseAllocated = 0;
        }

        ~PoolFactory()
        {
            clearAndDestroy();
        }

        T* getNext()
        {
            if ( (miReUseIndex + 1) < miReUseAllocated)
            {
                miReUseIndex++;
                return mReusableList[miReUseIndex];
            }
            miNext++;
            if (miNext >= miNumberAllocated)
            {
                mFactoryList.push_back(new T);
                miNumberAllocated++;
            }
            return mFactoryList[miNext];
        }

        void clear()
        {
            miNext = -1;
            mReusableList.clear();

            miReUseIndex = -1;
            miReUseAllocated = 0;
        }

        void clearAndDestroy()
        {
            miNext = -1;
            miNumberAllocated = 0;
            miReUseIndex = -1;

            for (unsigned int i = 0; i < mFactoryList.size(); i++)
            {
                delete mFactoryList[i];
            }

            mFactoryList.clear();
            mReusableList.clear();
        }

        void releaseNode( T* rec )
        {
            mReusableList.push_back(rec);
            miReUseAllocated++;
        }

        private:

        int              miNumberAllocated;
        int              miNext;
        int              miReUseIndex;
        int              miReUseAllocated;

        vector<T *>      mFactoryList;
        vector<T *>      mReusableList;
      };
} // PFL Namespace

#endif
