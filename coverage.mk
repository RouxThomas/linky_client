include $(ROOT_DIR)/def_native.mk

compute_info_cov:
	$(LCOV) --directory $(OBJ_DIR) \
            --base-directory $(SRC_DIR) \
            --output-file $(OBJ_DIR)/coverage.info \
            --no-external \
            --capture \
            --ignore-errors source


