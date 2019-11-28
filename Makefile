.PHONY: clean All

All:
	@echo "----------Building project:[ CRC - Debug ]----------"
	@cd "CRC" && "$(MAKE)" -f  "CRC.mk"
clean:
	@echo "----------Cleaning project:[ CRC - Debug ]----------"
	@cd "CRC" && "$(MAKE)" -f  "CRC.mk" clean
