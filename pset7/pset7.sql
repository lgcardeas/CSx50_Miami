-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Mar 24, 2017 at 11:45 PM
-- Server version: 5.5.50-0ubuntu0.14.04.1
-- PHP Version: 5.5.9-1ubuntu4.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `pset7`
--

-- --------------------------------------------------------

--
-- Table structure for table `history`
--

CREATE TABLE IF NOT EXISTS `history` (
  `method` varchar(5) NOT NULL,
  `date` datetime NOT NULL,
  `symbol` varchar(15) NOT NULL,
  `shares` int(11) NOT NULL,
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `price` decimal(65,2) NOT NULL,
  `user_id` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `portfolios`
--

CREATE TABLE IF NOT EXISTS `portfolios` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `symbol` varchar(15) NOT NULL,
  `shares` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `user_id` (`user_id`,`symbol`),
  UNIQUE KEY `user_id_2` (`user_id`,`symbol`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=12 ;

--
-- Dumping data for table `portfolios`
--

INSERT INTO `portfolios` (`id`, `user_id`, `symbol`, `shares`) VALUES
(2, 5, 'FREee', 2),
(9, 12, 'free', 40),
(10, 12, 'sd', 100),
(11, 12, 'kkkk', 0);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=16 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `cash`, `username`, `hash`) VALUES
(1, 10000.0000, 'andi', '$2y$10$c.e4DK7pVyLT.stmHxgAleWq4yViMmkwKz3x8XCo4b/u3r8g5OTnS'),
(2, 10000.0000, 'caesar', '$2y$10$0p2dlmu6HnhzEMf9UaUIfuaQP7tFVDMxgFcVs0irhGqhOxt6hJFaa'),
(3, 0.0000, 'eli', '$2y$10$COO6EnTVrCPCEddZyWeEJeH9qPCwPkCS0jJpusNiru.XpRN6Jf7HW'),
(4, 0.0000, 'hdan', '$2y$10$o9a4ZoHqVkVHSno6j.k34.wC.qzgeQTBHiwa3rpnLq7j2PlPJHo1G'),
(5, 0.0000, 'jason', '$2y$10$ci2zwcWLJmSSqyhCnHKUF.AjoysFMvlIb1w4zfmCS7/WaOrmBnLNe'),
(6, 0.0000, 'john', '$2y$10$dy.LVhWgoxIQHAgfCStWietGdJCPjnNrxKNRs5twGcMrQvAPPIxSy'),
(7, 0.0000, 'levatich', '$2y$10$fBfk7L/QFiplffZdo6etM.096pt4Oyz2imLSp5s8HUAykdLXaz6MK'),
(8, 0.0000, 'rob', '$2y$10$3pRWcBbGdAdzdDiVVybKSeFq6C50g80zyPRAxcsh2t5UnwAkG.I.2'),
(9, 0.0000, 'skroob', '$2y$10$395b7wODm.o2N7W5UZSXXuXwrC0OtFB17w4VjPnCIn/nvv9e4XUQK'),
(10, 0.0000, 'zamyla', '$2y$10$UOaRF0LGOaeHG4oaEkfO4O7vfI34B1W23WqHr9zCpXL68hfQsS3/e'),
(12, 2918.6500, 'lgcardenas91', '$2y$10$VnfNmgjuT6as90vg46iTce22Qz1TCxWcsXYUyFOHzJLc8.Y1vuNai'),
(13, 10000.0000, 'n', '$2y$10$1qBlYz9Pnc0tBoqC0GccVOlXicpO8kDWrjxm8mCwk/uIdqi0GpdW2'),
(14, 10000.0000, 'asd', '$2y$10$EqyT4Jecf7ck73oDqS.TG.rMyL4mNd/zZB6QWOkr3jO3Fsm6D5tla'),
(15, 10000.0000, 'dsa', '$2y$10$ughx41EYREcJFQcAP1sKxe.WipSAbJhWEtV1Lj.tV6giGCqfTbWwO');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
