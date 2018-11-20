-- ---
-- Globals
-- ---

-- SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
-- SET FOREIGN_KEY_CHECKS=0;

-- ---
-- Table 'empleados'
-- 
-- ---

DROP TABLE IF EXISTS `empleados`;
		
CREATE TABLE `empleados` (
  `id` INTEGER NULL AUTO_INCREMENT DEFAULT NULL,
  `Nombre` VARCHAR(80) NULL DEFAULT NULL,
  `tel` VARCHAR(15) NULL DEFAULT NULL,
  PRIMARY KEY (`id`)
);

-- ---
-- Table 'servicios'
-- 
-- ---

DROP TABLE IF EXISTS `servicios`;
		
CREATE TABLE `servicios` (
  `id` INTEGER NULL AUTO_INCREMENT DEFAULT NULL,
  `tipo` VARCHAR(80) NULL DEFAULT NULL,
  `valor` INTEGER(2) NULL DEFAULT NULL,
  PRIMARY KEY (`id`)
);

-- ---
-- Table 'registro'
-- 
-- ---

DROP TABLE IF EXISTS `registro`;
		
CREATE TABLE `registro` (
  `id` INTEGER NULL AUTO_INCREMENT DEFAULT NULL,
  `mes` INTEGER(2) NULL DEFAULT NULL,
  `dia` INTEGER(2) NULL DEFAULT NULL,
  `placa` VARCHAR(8) NULL DEFAULT NULL,
  `servicio` VARCHAR(10) NULL DEFAULT NULL,
  `empleado` INT(2) NULL DEFAULT NULL,
  `precio` INT(2) NULL DEFAULT NULL,
  PRIMARY KEY (`id`)
);

-- ---
-- Table 'meses'
-- 
-- ---

DROP TABLE IF EXISTS `meses`;
		
CREATE TABLE `meses` (
  `id` INTEGER NULL AUTO_INCREMENT DEFAULT NULL,
  `mes` VARCHAR(10) NULL DEFAULT NULL,
  `avrev` VARCHAR(5) NULL DEFAULT NULL,
  PRIMARY KEY (`id`)
);

-- ---
-- Foreign Keys 
-- ---


-- ---
-- Table Properties
-- ---

-- ALTER TABLE `empleados` ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
-- ALTER TABLE `servicios` ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
-- ALTER TABLE `registro` ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
-- ALTER TABLE `meses` ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- ---
-- Test Data
-- ---

-- INSERT INTO `empleados` (`id`,`Nombre`,`tel`) VALUES
-- ('','','');
-- INSERT INTO `servicios` (`id`,`tipo`,`valor`) VALUES
-- ('','','');
-- INSERT INTO `registro` (`id`,`mes`,`dia`,`placa`,`servicio`,`empleado`,`precio`) VALUES
-- ('','','','','','','');
-- INSERT INTO `meses` (`id`,`mes`,`avrev`) VALUES
-- ('','','');


