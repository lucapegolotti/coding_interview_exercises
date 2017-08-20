#!bin/bash

ROOT=$(pwd)

if make; then
  DATA_STRUCTURES_TESTS_DIR=$ROOT/data_structures/tests
  CHAPTER_ONE_DIR=$ROOT/chapter_one
  CHAPTER_TWO_DIR=$ROOT/chapter_two

  cd $DATA_STRUCTURES_TESTS_DIR
  bash ./test_all.sh
  cd $CHAPTER_ONE_DIR
  bash ./run_all.sh
  cd $CHAPTER_TWO_DIR
  bash ./run_all.sh
fi
