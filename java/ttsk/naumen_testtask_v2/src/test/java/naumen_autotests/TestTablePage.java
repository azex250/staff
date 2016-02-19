package naumen_autotests;

/**
 * Created by az on 30.01.16.
 */


import naumen_autotests.pages.TablePage;
import static org.junit.Assert.assertTrue;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class TestTablePage {
    private TablePage page;

    @Before
    public void setUp() {
        page = new TablePage();
    }

    @Test
    public void changeContactName() {
        String expected_name = "mr. Smith";

        page.setContactFirstNameByRow(1, expected_name);

        assertTrue("Change contact name: Expected to change contact name",
                page.getContactFirstNameByRow(1).equals(expected_name));
    }

    @Test
    public void goToTableEnd() {
        page.goToEnd();
        page.getRowsCount();

        assertTrue("Go to table end: expected to bottom border matches with rows count",
                page.getRowsCount() == page.getRowsShownCount());
    }

    @Test
    public void sortByFirstName() {
        page.sortByFirstName();
        String first = page.getContactFirstNameByRow(1);
        page.goToEnd();
        String last = page.getContactFirstNameByRow(page.getRowsShownCount() - 1);

        assertTrue("Sort by first name: expected that first row's name less than last",
                last.compareTo(first) >= 0);
    }

    @Test
    public void paginationStep() {
        int rows_count = page.getRowsCount();
        int expectet_show_rows = page.getRowsShownCount() + 15;

        page.stepForward();
        int show_rows = page.getRowsShownCount();
        assertTrue("Expected step to 15 rows or lower boubdary",
                show_rows == expectet_show_rows || show_rows == rows_count);
    }

    @After
    public void afterTests() {
        page.quit();
    }
}

