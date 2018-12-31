#pragma once

#include <catch/catch.hpp>

namespace Catch{
   struct GMockCatchListener: public Catch::TestEventListenerBase {
      using TestEventListenerBase::TestEventListenerBase; // inherit constructor

      // The whole test run, starting and ending
      virtual void testRunStarting( Catch::TestRunInfo const& testRunInfo ){};
      virtual void testRunEnded( Catch::TestRunStats const& testRunStats ){};

      // Test cases starting and ending
      virtual void testCaseStarting( Catch::TestCaseInfo const& testInfo ){};
      virtual void testCaseEnded( Catch::TestCaseStats const& testCaseStats ){};

      // Sections starting and ending
      virtual void sectionStarting( Catch::SectionInfo const& sectionInfo ){};
      virtual void sectionEnded( Catch::SectionStats const& sectionStats ){};

      // Assertions before/ after
      virtual void assertionStarting( Catch::AssertionInfo const& assertionInfo ){};
      virtual bool assertionEnded( Catch::AssertionStats const& assertionStats ){};

      // A test is being skipped (because it is "hidden")
      virtual void skipTest( Catch::TestCaseInfo const& testInfo ){};
   };
   
   CATCH_REGISTER_LISTENER(GMockCatchListener)
}

