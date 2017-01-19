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
	EXPECT_FALSE(parser.Parse("invalideof", &out_config));
}

TEST_F(NginxConfigParserTest, TestInput2){
	EXPECT_FALSE(parser.Parse("unmatchedbrace", &out_config));
}