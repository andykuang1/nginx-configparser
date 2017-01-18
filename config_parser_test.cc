#include "gtest/gtest.h"
#include "config_parser.h"

class NginxConfigParserTest : public ::testing::Test{
	protected:
		NginxConfigParser parser;
  		NginxConfig out_config;
};

TEST_F(NginxConfigParserTest, SimpleConfig) {

  bool success = parser.Parse("example_config", &out_config);

  EXPECT_TRUE(success);
  EXPECT_EQ(out_config.ToString(0), "foo \"bar\";\n");

  bool success2 = parser.Parse("example_config2", &out_config);
  EXPECT_FALSE(success2);
}

TEST_F(NginxConfigParserTest, TestInput){
	bool success = parser.Parse("invalideof", &out_config);

	EXPECT_FALSE(success);
}

TEST_F(NginxConfigParserTest, TestInput2){
	bool success = parser.Parse("unmatchedbrace", &out_config);
	EXPECT_FALSE(success);
}